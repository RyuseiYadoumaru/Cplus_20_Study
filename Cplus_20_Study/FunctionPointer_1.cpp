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

	//__stdcallでthisポインタに相当する情報を
	//レジスタにpushする
	//呼出規約 calling convention
	int __stdcall g()
	{
		void* p = this;
		return n;
	}

};

//関数ポインタを使ってみた
void Function_one()
{
	CMyClass ins;
	ins.n = 123;
	int(__stdcall CMyClass:: * p)();
	p = &CMyClass::g;

	//(CMyClass*)を隠し引数にする
	int(__stdcall * q)(CMyClass*);

	q = (int(__stdcall*)(CMyClass*)) * (void**)(&p);
	int a = (*q)(&ins);
	a;
}

//関数ポインタを使ってみた２
void Function_Two()
{
	CMyClass ins;
	ins.n = 123;
	//呼出規約があるため統一する
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