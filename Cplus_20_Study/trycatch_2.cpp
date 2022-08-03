#include <new>
#include <iostream>

void g(char* p)
{
	//pの処理を想定する
	throw std::runtime_error("エラーが発生しました");
}

void f()
{
	const auto p = new char[256];
	g(p);
	delete[] p;
}

#include <crtdbg.h>
int main()
{
	//メモリリーク検出
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG | _CRTDBG_LEAK_CHECK_DF));

	//tryブロック
	try
	{
		f();
	}
	catch (const std::exception& error)
	{

		std::cout << error.what() << std::endl;
	}

}