#include "main.h"
template<class T> int f(const T& fn)
{
	std::cin >> a;
	return 10 * fn(a);
}

int main()
{
	std::string prompt = "�f�[�^����͂��Ă�������";

	const auto n = f([]() {return 100; });
	const auto n2 = f([&prompt](int a)
		{
			std::cout << prompt << ":";
			int num;
			std::cin >> num;
			return num + a;
		});
}