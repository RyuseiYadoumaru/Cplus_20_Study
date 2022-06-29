//	Concepts：コンセプト
//	C++20から導入。テンプレートパラメータを制約
//	https://cpprefjp.github.io/lang/cpp20/concepts.html

#include <type_traits>
#include <iterator>
#include <utility>
#include <concepts>
#include <string>
#include <vector>
#include <concepts>
#include <cmath>
#include <limits>
#include <cassert>
#include <iostream>


//メンバ関数を持っているか要求する制約の定義例
#pragma region requires
//メンバ関数Draw()を持つことを要求する
template <class T>
concept Drawble = requires(T & x)
{
	x.Draw();
};


//テンプレートパラメータTをコンセプトDrawbleで制約
//Drawbleの要件を満たさない型が渡された場合はエラーになる
template<Drawble T>
void Func(T& x)
{
	x.Draw();
}

//Drawあり
class GameObject
{
public:
	void Draw() {}
};

//Draw継承
class Player : public GameObject
{

};

//DrawがPrivate
class GameObject_private
{
private:
	void Draw() {}
};

//Drawなし
class System
{
public:
	void SetUp() {}
};
#pragma endregion メンバ関数を制限する




//型に対する要求の集合であるコンセプトを定義する
//型がどのような特性を持つのか（整数型？浮動小数型？）(==で比較可能か、<で順序付けられるか)
//型に対してどのような操作ができるのか（メンバ関数の呼び出し、他の型との演算）
#pragma region 

//すでに用意されている定数式をラップしてコンセプトを定義
template <class T>
concept Integral = std::is_integral_v<T>;

//2つ以上のテンプレートを取るコンセプト
template<class T, class U>
concept EqualityComparable = requires(T a, U b)
{
	//式の戻り値型を制約。直接戻り値型は指定できない
	{a == b} -> std::convertible_to<bool>;
};

//戻り値型の要求には直接の型ではなくコンセプトも使える
template <class T, class U>
concept Addable = requires(T a, U b)
{
	//加算結果として型Tと型Uの共通の型が変えること
	{a + b} -> std::common_with<T>;
};

//セミコロン区切りで複数要求を列挙できる
template <class T>
concept SequenceContainer = requires(T c)
{
	//型Tがメンバ型としてsize_typeを持っていること
	typename T::size_type;

	//型Tのオブジェクトに対して特定のメンバ関数が呼び出せる
	{c.size()} -> std::convertible_to<typename T::size_type>;

	//非メンバ関数の呼び出しも要求できる
	{std::size(c)} -> std::convertible_to<typename T::size_type>;

	typename T::value_type;
	c.push_back(std::declval<typename T::value_type>());

};
#pragma endregion 型の制限




//static_assertとコンセプトの違い
//static_assert	：要件を満たさない場合に即座にコンパイルエラーになる
//コンセプト	：要件を満たさない場合にほかの候補を探す
//関数テンプレートのオーバーロード、クラステンプレート、変数テンプレートの特殊化に使用する。
#pragma region 

//数値の等値比較を行う関数を整数型か浮動少数型かでオーバーロードする
template <std::integral T>
bool equal(T a, T b)
{
	return a == b;
}

template <std::floating_point T>
bool equal(T a, T b)
{
	//std::numeric_limits<T>::epsilon()：浮動小数点の比較のために計算誤差を許容するを等値比較
	return std::abs(a - b) <= std::numeric_limits<T>::epsilon();
}

//変数テンプレートを整数型か浮動小数型かで特殊化する
//クラステンプレートでも同じことができる
template<class T>
constexpr T pi;

template <std::floating_point T>
constexpr T pi<T> = static_cast<T>(3.141592653589793);

template <std::integral T>
constexpr T pi<T> = static_cast<T>(3);



#pragma endregion コンセプトのオーバーロードと特殊化



int main()
{
	//メンバ関数の制限
	{

		GameObject obj;
		Func(obj);

		//DrawPrivate
		//GameObject_private obj_DrawPrivate;
		//Func(obj_DrawPrivate);

		Player player;
		Func(player);

		//NotDrawFunction
		//System sys;
		//Func(sys);
	}

	//コンセプトをbool定数式として使用できる
	{
		static_assert(Integral<int>);
		static_assert(EqualityComparable<int, int>);
		static_assert(Addable<std::string, char>);
		static_assert(SequenceContainer<std::vector<int>>);
	}

	//オーバーロードと特殊化しました。
	{
		assert(equal(1 + 2, 3));

		//計算誤差によって0.1 + 0.2 == 0.3にはならないが
		//誤差を許容することで等値と見なす。
		//(0.1 + 0.2 は 0.30000000000000004 のような値になる)
		assert(equal(0.1 + 0.2, 0.3));

		std::cout << pi<double> << std::endl; // 3.14159
		std::cout << pi<int> << std::endl;    // 3
	}

	return 0;
}