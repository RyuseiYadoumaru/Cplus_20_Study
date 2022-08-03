#include <new>
#include <iostream>

void f()
{
	//例外が投入(throw)される
	throw std::runtime_error("エラーが発生しました");
	//std::runtime_errorクラスはstd::exeptionの派生クラス

}

int main()
{
	//tryブロック
	try
	{
		//例外が投入(throw)される
		//throw std::runtime_error("エラーが発生しました");
		//std::runtime_errorクラスはstd::exeptionの派生クラス
		//関数にしても適切にthrowされる
		f();
	}
	catch (const std::exception& error)
	{
		//補足(catch)される
		std::cout << error.what() << std::endl;
	}

}