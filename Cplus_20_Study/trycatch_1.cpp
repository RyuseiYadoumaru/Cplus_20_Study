#include <new>
#include <iostream>

void f()
{
	//��O������(throw)�����
	throw std::runtime_error("�G���[���������܂���");
	//std::runtime_error�N���X��std::exeption�̔h���N���X

}

int main()
{
	//try�u���b�N
	try
	{
		//��O������(throw)�����
		//throw std::runtime_error("�G���[���������܂���");
		//std::runtime_error�N���X��std::exeption�̔h���N���X
		//�֐��ɂ��Ă��K�؂�throw�����
		f();
	}
	catch (const std::exception& error)
	{
		//�⑫(catch)�����
		std::cout << error.what() << std::endl;
	}

}