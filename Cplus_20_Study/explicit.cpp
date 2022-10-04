//*****************************************************************************
//* @file   explicit.cpp
//* @brief  explicitの勉強です
//* @note   暗黙的型変換を防止します
//* @note   演算子やコンストラクタ、関数に対して明示的に型変換を行います
//* https://cpprefjp.github.io/lang/cpp20/explicit_bool.html
//* https://cpprefjp.github.io/lang/cpp11/explicit_conversion_operator.html
//* https://komorinfo.com/blog/cpp-explicit-specifier/
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#include <iostream>

#pragma region  C+3
/**
 * クラスのコンストラクタ宣言に対してexplicitをつける
 * コピー初期化ができない。暗黙の型変換ができない
 * C+03.
 */
class Test1
{
public:
	explicit Test1(int num) : m_num(num) {}
	inline void PrintNum()
	{
		std::cout << "test1 : " << m_num << std::endl;
	}

private:
	int m_num;

};

class Test2
{
public:
	Test2(int num) : m_num(num) {}
	inline void PrintNum()
	{
		std::cout << "test2 : " << m_num << std::endl;
	}

private:
	int m_num;

};

void hoge1(Test1 test) {}
void hoge2(Test2 test) {}

#pragma endregion


int main()
{
	// コピー初期化
	Test1 test1(10);
	//Test1 test1_copy = 0;	//コピー初期化ができない
	Test2 test2 = 0;		//コピー初期化ができてしまう
	Test1 test1_copy = Test1(9);
	Test2 test2_copy = Test2(9);

	// 暗黙の型変換
	hoge1(Test1(0));	//明示的な型変換
	hoge2(Test2(0));	//明示的な型変換
	
	//hoge1(0);			//暗黙的な型変換ができない
	hoge2(0);			//暗黙的な型変換




}
