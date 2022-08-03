#include <new>
#include <iostream>

struct  sample
{
	//メンバ変数の初期化を:変数名{}で行っている
	sample()
		: n{}
	{
		std::cout << __FUNCTION__ << "\n";
	}

	~sample()
	{
		std::cout << __FUNCTION__ << "\n";
	}
	int n;
};

int main()
{
	//bufのメモリ領域にsampleを作成する
	char buf[sizeof(sample)];
	const auto p = new(buf) sample;
	p->n = 10;
}