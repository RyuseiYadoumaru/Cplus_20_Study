#include<stdlib.h>
#include <iostream>
struct  sample
{
	//�����o�ϐ��̏�������:�ϐ���{}�ōs���Ă���
	sample()
		:buf{}
		, n{}
	{
		std::cout << "�R���X�g���N�^���Ăяo����܂���\n";
	}

	~sample()
	{
		std::cout << "�f�X�g���N�^���Ăяo����܂���\n";
	}

	char buf[256];
	int n;
};



int main()
{
	//260�o�C�g���m�ۂ���
	//�A�h���X�̑���𖳌��ɂ���
	sample* const q = new sample;	//�I�u�W�F�N�g���쐬����, ���s�����std::bad_alloc��O�����������
	//const  auto q = new sample;
	//�@q++�ɂ���Ǝw�肷��A�h���X���ς���Ă��܂�
	//	const sample* const q = new sample;�@���ƃA�N�Z�X���ł��Ȃ��Ȃ�


	//�̈�����
	if (sample* const p = static_cast<sample*>(malloc(sizeof(sample))))
	{
		p->n = 10;
		//����
		free(p);	//�������
	}

	delete q;
}