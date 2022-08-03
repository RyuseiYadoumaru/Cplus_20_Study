#include <new>
#include <iostream>

struct  sample
{
	//ƒƒ“ƒo•Ï”‚Ì‰Šú‰»‚ğ:•Ï”–¼{}‚Ås‚Á‚Ä‚¢‚é
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
	//buf‚Ìƒƒ‚ƒŠ—Ìˆæ‚Ésample‚ğì¬‚·‚é
	char buf[sizeof(sample)];
	const auto p = new(buf) sample;
	p->n = 10;
}