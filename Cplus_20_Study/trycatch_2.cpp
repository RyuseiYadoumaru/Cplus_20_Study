#include <new>
#include <iostream>

void g(char* p)
{
	//p�̏�����z�肷��
	throw std::runtime_error("�G���[���������܂���");
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
	//���������[�N���o
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG | _CRTDBG_LEAK_CHECK_DF));

	//try�u���b�N
	try
	{
		f();
	}
	catch (const std::exception& error)
	{

		std::cout << error.what() << std::endl;
	}

}