//#include<stdlib.h>
//#include <iostream>
//struct  sample
//{
//	//メンバ変数の初期化を:変数名{}で行っている
//	sample()
//		:buf{}
//		, n{}
//	{
//		std::cout << this << "コンストラクタが呼び出されました\n";
//	}
//
//	~sample()
//	{
//		std::cout << this << "デストラクタが呼び出されました\n";
//	}
//
//	char buf[256];
//	int n;
//};
//
//
//
//int main()
//{
//	sample* const p = new sample[2];
//	p[0].n = 10;
//	p[1].n = 20;
//	delete[] p;
//
//	return 0;
//}