#include "main.h"

extern "C" void f(void(*p)(void));
void g()
{
	std::cout << "*";
}

int main()
{
	f(g);
	std::cout << "\n";
	//ラムダ式を用いることでC言語との連携もできる
	//ただし、C++からのキャプチャは別のやり方をしなければならない
	char ch = '+';
	//f([ch]() {std::cout << ch; });
	f([]() {std::cout << "/"; });

	return 0;

}