#include<stdlib.h>
#include <iostream>
struct  sample
{
	//メンバ変数の初期化を:変数名{}で行っている
	sample()
		:buf{}
		, n{}
	{
		std::cout << "コンストラクタが呼び出されました\n";
	}

	~sample()
	{
		std::cout << "デストラクタが呼び出されました\n";
	}

	char buf[256];
	int n;
};



int main()
{
	//260バイトを確保する
	//アドレスの操作を無効にする
	sample* const q = new sample;	//オブジェクトを作成する, 失敗するとstd::bad_alloc例外が投入される
	//const  auto q = new sample;
	//　q++にすると指定するアドレスが変わってしまう
	//	const sample* const q = new sample;　だとアクセスができなくなる


	//領域を作る
	if (sample* const p = static_cast<sample*>(malloc(sizeof(sample))))
	{
		p->n = 10;
		//成功
		free(p);	//解放する
	}

	delete q;
}