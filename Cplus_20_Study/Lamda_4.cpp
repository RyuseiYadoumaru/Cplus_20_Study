//******************************************************************************
//* @file   Lamda_4.cpp
//* @brief  
//* @note   ラムダ式の復習したいと思いました
//* @note	https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html
//* 
//* @author YadoumaruRyusei
//* @date   August 2022
//*****************************************************************************
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * ラムダ式(lambda expressions)
 * C+11から
 * 簡易的な関数オブジェクトをその場で定義するための機能
 * 
 * 利点
 * 高階関数（関数を引数もしくは戻り値とする関数）より使いやすい関数オブジェクトを作成できる.
 */

#pragma region
void TestCode_1()
{
	/** ラムダ式 */
	/**
	 * ラムダ式で定義された関数オブジェクトはautoを使用して方推論するか、
	 * std::functinoクラス変数に保持するか、いずれかの方法を取る必要がある.
	*/ 
	auto plus = [](int a, int b) {return a + b; };	
	int result = plus(2, 3);
}
#pragma endregion 基本

#pragma region 
void TestCode_2()
{
	/**
	 * ラムダ式から外部の変数に対して操作したいときは「キャプチャ(capture)」を使う
	 * ラムダ式の先頭にある[]は「ラムダ導入子(lambda-introducer)と呼ばれている」
	 * どの変数をどの様にキャプチャするかを指定する
	 * 参照かコピーでキャプチャ可能.
	 */

	/** 参照 */
	int x = 3;
	cout << "参照キャプチャ前 : X = " << x << endl;
	
	//この時点で見える自動変数参照でキャプチャし
	//参照したデータを書き換える
	auto f = [&] { x = 1; };

	//個別にキャプチャ方法を指定する場合は、
	//以下のように&の次に変数名を指定する
	//auto f = [&x]{ x = 1; };

	f();
	cout << "参照キャプチャ後 : X = " << x << endl;


	/** コピー */
	int x_copy = 3;
	cout << "コピーキャプチャ前 : X = " << x_copy << endl;

	//この時点で見える自動変数をコピーでキャプチャにコピーする
	auto f_copy = [=] {return x_copy + 1; };

	//個別に指定する場合
	//auto f_copy = [x_copy] {return x_copy + 1; };

	f_copy();
	cout << "コピーキャプチャ後 : X = " << x_copy << endl;
	cout << "ラムダ戻り値 : X = " << f_copy() << endl;

}
#pragma endregion 参照とコピーキャプチャ

#pragma region
/**
 * thisをキャプチャした場合、ラムダ式によって定義された関数オブジェクトは
 * thisクラスのfriendの扱いになる。privateメンバにもアクセスできる.
 */

class CTest
{
public:
	void Foo()
	{

		int copyValue = 4;
		
		/** ラムダ式 */
		auto f = [this, copyValue]
		{
			/** プライベートなメンバ変数、メンバ関数を呼ぶ */
			hp = 100;
			DebugStatus();

			//コピーキャプチャしたローカル変数を使用する
			return copyValue * 2;
		};

		//auto f_2 = []
		//{
		//	/** thisをキャプチャしてないのでアクセスできない */
		//	hp = 200;	
		//	name = "aaa"
		//}

		int ret = f();
		cout << "CopyValue : " << copyValue << endl;
		cout << "Result : " << ret << endl;

	}


public:
	string name = "name";
private:
	void DebugStatus()
	{
		cout << "=============STATUS==============\n";
		cout << "HP : " << hp << endl;
		cout << "ATK : " << atk << endl;
		cout << "DEF : " << def << endl;
	}

private:
	int hp = 90;
	int atk = 100;
	int def = 200;
};


void TestCode_3()
{
	CTest().Foo();
}

#pragma endregion クラス

#pragma region 
/**
 * ラムダ式が一つ以上の変数を参照キャプチャしているとき、
 * 参照している変数の寿命が切れた後の、ラムダ式のコピーと呼び出し動作が未定義になる.
 */

//これだと未定義になる！！！
std::function<int(int)> TestCode_4()
{
	int n = 3;
	return [&n](int i) -> int {return n + i; };
}


//ラムダ式にデフォルト引数を入れる場合いかなる場合でもキャプチャしてはならない

void TestCode_5()
{
	int x = 3;

	/** ローカル関数の宣言 */
	//void f1(int = ([x] {return x; }());	//コンパイルエラー
	//void f2(int = ([x] {return 0; }());	//コンパイルエラー
	//void f3(int = ([=] {return x; }()));	//コンパイルエラー
	void f4(int = ([=] {return 0; })());	//OK : デフォルトキャプチャしたが、使用していない
	void f5(int = ([] {return sizeof(x); })());		//OK : キャプチャなし
}


#pragma endregion 引数入れてみたお

#pragma region 
/**
 * mutable
 * キャプチャした変数はクロージャーオブジェクトのメンバ変数とみなされ、
 * クロージャーオブジェクトの関数呼び出し演算子は、デフォルトでconst修飾される
 * そのためコピーキャプチャした変数をラムダ式で書き換えることができない.
 */
void TestCode_6()
{
	//int rate = 2;
	//[rate](int x) -> int {return x * ++rate; }	//rate変数を書き換えることができない

	/**
	 * コピーキャプチャした変数を書き換えたい場合は、
	 * ラムダ式のパラメータリスト後ろにmutableを記述する. 
	*/

	int rate = 2;
	auto f = [rate](int x) mutable -> int {return x * ++rate; };
	cout << f(4) << endl;

}
#pragma endregion mutable

#pragma region 
/**
 * クロージャーオブジェクトは同じパラメータ型と戻り値型のシグニチャをもつ関数ポインタ
 * に変換できる.
 */

void Foo(int(*fp)(int, int))
{
	int result = fp(2, 3);
	cout << result << endl;
}

void TestCode_7()
{
	/** 関数ポインタが引数の関数にラムダ式を渡す */
	Foo([](int a, int b) {return a + b; });
}

#pragma endregion 関数ポインタ

#pragma region 

/**
 * アルゴリズムの引数として関数を渡す.
 */
void TestCode_8()
{
	vector<int> v = { 1,2,3,4,5 };
	//条件の一致する最初の要素を検索する
	decltype(v)::iterator it = std::find_if(
											v.begin(),
											v.end(),
											[](int x) {return x % 2 == 0; }
											);

	//見つかった
	if (it != v.end())
	{
		int foundValue = *it;
		cout << foundValue << endl;
	}
}


/**
 * 処理完了時の通知処理を引数で渡す.
 */

void Task(std::function<void()> onCompleteFunc)
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}

	//完了ハンドラを呼び出す
	onCompleteFunc();
}


void TestCode_9()
{
	//処理が完了していた時に呼ばれる関数を指定する
	Task([] {cout << "Complete\n"; });
}



#pragma endregion 応用



int main()
{
	//TestCode_1();
	//TestCode_2();
	//TestCode_3();
	//int ret = TestCode_4()(2);
	//cout << ret << endl;
	//TestCode_5();
	//TestCode_6();
	//TestCode_7();
	TestCode_8();
	TestCode_9();
	
	return 0;
}