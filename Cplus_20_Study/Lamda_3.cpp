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
	//�����_����p���邱�Ƃ�C����Ƃ̘A�g���ł���
	//�������AC++����̃L���v�`���͕ʂ̂��������Ȃ���΂Ȃ�Ȃ�
	char ch = '+';
	//f([ch]() {std::cout << ch; });
	f([]() {std::cout << "/"; });

	return 0;

}