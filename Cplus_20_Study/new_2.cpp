#include <new>
#include <iostream>

struct  sample
{
	//�����o�ϐ��̏�������:�ϐ���{}�ōs���Ă���
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
	//buf�̃������̈��sample���쐬����
	char buf[sizeof(sample)];
	const auto p = new(buf) sample;
	p->n = 10;
}