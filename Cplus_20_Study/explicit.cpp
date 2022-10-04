//*****************************************************************************
//* @file   explicit.cpp
//* @brief  explicit�̕׋��ł�
//* @note   �ÖٓI�^�ϊ���h�~���܂�
//* @note   ���Z�q��R���X�g���N�^�A�֐��ɑ΂��Ė����I�Ɍ^�ϊ����s���܂�
//* https://cpprefjp.github.io/lang/cpp20/explicit_bool.html
//* https://cpprefjp.github.io/lang/cpp11/explicit_conversion_operator.html
//* https://komorinfo.com/blog/cpp-explicit-specifier/
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#include <iostream>

#pragma region  C+3
/**
 * �N���X�̃R���X�g���N�^�錾�ɑ΂���explicit������
 * �R�s�[���������ł��Ȃ��B�Öق̌^�ϊ����ł��Ȃ�
 * C+03.
 */
class Test1
{
public:
	explicit Test1(int num) : m_num(num) {}
	inline void PrintNum()
	{
		std::cout << "test1 : " << m_num << std::endl;
	}

private:
	int m_num;

};

class Test2
{
public:
	Test2(int num) : m_num(num) {}
	inline void PrintNum()
	{
		std::cout << "test2 : " << m_num << std::endl;
	}

private:
	int m_num;

};

void hoge1(Test1 test) {}
void hoge2(Test2 test) {}

#pragma endregion


int main()
{
	// �R�s�[������
	Test1 test1(10);
	//Test1 test1_copy = 0;	//�R�s�[���������ł��Ȃ�
	Test2 test2 = 0;		//�R�s�[���������ł��Ă��܂�
	Test1 test1_copy = Test1(9);
	Test2 test2_copy = Test2(9);

	// �Öق̌^�ϊ�
	hoge1(Test1(0));	//�����I�Ȍ^�ϊ�
	hoge2(Test2(0));	//�����I�Ȍ^�ϊ�
	
	//hoge1(0);			//�ÖٓI�Ȍ^�ϊ����ł��Ȃ�
	hoge2(0);			//�ÖٓI�Ȍ^�ϊ�




}
