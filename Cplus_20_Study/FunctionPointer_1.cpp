#include "main.h"

#include <iostream>
class main
{
};


class CMyClass
{
public:

	int n;

	int fun(int(CMyClass::* get)(), CMyClass* q)
	{
		return (q->*get)();

	}

	//__stdcall��this�|�C���^�ɑ����������
	//���W�X�^��push����
	//�ďo�K�� calling convention
	int __stdcall g()
	{
		void* p = this;
		return n;
	}

};

//�֐��|�C���^���g���Ă݂�
void Function_one()
{
	CMyClass ins;
	ins.n = 123;
	int(__stdcall CMyClass:: * p)();
	p = &CMyClass::g;

	//(CMyClass*)���B�������ɂ���
	int(__stdcall * q)(CMyClass*);

	q = (int(__stdcall*)(CMyClass*)) * (void**)(&p);
	int a = (*q)(&ins);
	a;
}

//�֐��|�C���^���g���Ă݂��Q
void Function_Two()
{
	CMyClass ins;
	ins.n = 123;
	//�ďo�K�񂪂��邽�ߓ��ꂷ��
	int(__stdcall CMyClass:: * p)();
	p = &CMyClass::g;

	int a = ins.fun(p, &ins);
	a;
}


int main()
{
	//Function_one();
	//Function_Two();
	return 0;
}