//******************************************************************************
//* @file   Lamda_4.cpp
//* @brief  
//* @note   �����_���̕��K�������Ǝv���܂���
//* @note	https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html
//* 
//* @author YadoumaruRyusei
//* @date   August 2022
//*****************************************************************************
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * �����_��(lambda expressions)
 * C+11����
 * �ȈՓI�Ȋ֐��I�u�W�F�N�g�����̏�Œ�`���邽�߂̋@�\
 * 
 * ���_
 * ���K�֐��i�֐��������������͖߂�l�Ƃ���֐��j���g���₷���֐��I�u�W�F�N�g���쐬�ł���.
 */

#pragma region
void TestCode_1()
{
	/** �����_�� */
	/**
	 * �����_���Œ�`���ꂽ�֐��I�u�W�F�N�g��auto���g�p���ĕ����_���邩�A
	 * std::functino�N���X�ϐ��ɕێ����邩�A�����ꂩ�̕��@�����K�v������.
	*/ 
	auto plus = [](int a, int b) {return a + b; };	
	int result = plus(2, 3);
}
#pragma endregion ��{

#pragma region 
void TestCode_2()
{
	/**
	 * �����_������O���̕ϐ��ɑ΂��đ��삵�����Ƃ��́u�L���v�`��(capture)�v���g��
	 * �����_���̐擪�ɂ���[]�́u�����_�����q(lambda-introducer)�ƌĂ΂�Ă���v
	 * �ǂ̕ϐ����ǂ̗l�ɃL���v�`�����邩���w�肷��
	 * �Q�Ƃ��R�s�[�ŃL���v�`���\.
	 */

	/** �Q�� */
	int x = 3;
	cout << "�Q�ƃL���v�`���O : X = " << x << endl;
	
	//���̎��_�Ō����鎩���ϐ��Q�ƂŃL���v�`����
	//�Q�Ƃ����f�[�^������������
	auto f = [&] { x = 1; };

	//�ʂɃL���v�`�����@���w�肷��ꍇ�́A
	//�ȉ��̂悤��&�̎��ɕϐ������w�肷��
	//auto f = [&x]{ x = 1; };

	f();
	cout << "�Q�ƃL���v�`���� : X = " << x << endl;


	/** �R�s�[ */
	int x_copy = 3;
	cout << "�R�s�[�L���v�`���O : X = " << x_copy << endl;

	//���̎��_�Ō����鎩���ϐ����R�s�[�ŃL���v�`���ɃR�s�[����
	auto f_copy = [=] {return x_copy + 1; };

	//�ʂɎw�肷��ꍇ
	//auto f_copy = [x_copy] {return x_copy + 1; };

	f_copy();
	cout << "�R�s�[�L���v�`���� : X = " << x_copy << endl;
	cout << "�����_�߂�l : X = " << f_copy() << endl;

}
#pragma endregion �Q�ƂƃR�s�[�L���v�`��

#pragma region
/**
 * this���L���v�`�������ꍇ�A�����_���ɂ���Ē�`���ꂽ�֐��I�u�W�F�N�g��
 * this�N���X��friend�̈����ɂȂ�Bprivate�����o�ɂ��A�N�Z�X�ł���.
 */

class CTest
{
public:
	void Foo()
	{

		int copyValue = 4;
		
		/** �����_�� */
		auto f = [this, copyValue]
		{
			/** �v���C�x�[�g�ȃ����o�ϐ��A�����o�֐����Ă� */
			hp = 100;
			DebugStatus();

			//�R�s�[�L���v�`���������[�J���ϐ����g�p����
			return copyValue * 2;
		};

		//auto f_2 = []
		//{
		//	/** this���L���v�`�����ĂȂ��̂ŃA�N�Z�X�ł��Ȃ� */
		//	hp = 200;	
		//	name = "aaa"
		//}

		int ret = f();
		cout << "CopyValue : " << copyValue << endl;
		cout << "Result : " << ret << endl;

	}


public:
	string name = "name";
private:
	void DebugStatus()
	{
		cout << "=============STATUS==============\n";
		cout << "HP : " << hp << endl;
		cout << "ATK : " << atk << endl;
		cout << "DEF : " << def << endl;
	}

private:
	int hp = 90;
	int atk = 100;
	int def = 200;
};


void TestCode_3()
{
	CTest().Foo();
}

#pragma endregion �N���X

#pragma region 
/**
 * �����_������ȏ�̕ϐ����Q�ƃL���v�`�����Ă���Ƃ��A
 * �Q�Ƃ��Ă���ϐ��̎������؂ꂽ��́A�����_���̃R�s�[�ƌĂяo�����삪����`�ɂȂ�.
 */

//���ꂾ�Ɩ���`�ɂȂ�I�I�I
std::function<int(int)> TestCode_4()
{
	int n = 3;
	return [&n](int i) -> int {return n + i; };
}


//�����_���Ƀf�t�H���g����������ꍇ�����Ȃ�ꍇ�ł��L���v�`�����Ă͂Ȃ�Ȃ�

void TestCode_5()
{
	int x = 3;

	/** ���[�J���֐��̐錾 */
	//void f1(int = ([x] {return x; }());	//�R���p�C���G���[
	//void f2(int = ([x] {return 0; }());	//�R���p�C���G���[
	//void f3(int = ([=] {return x; }()));	//�R���p�C���G���[
	void f4(int = ([=] {return 0; })());	//OK : �f�t�H���g�L���v�`���������A�g�p���Ă��Ȃ�
	void f5(int = ([] {return sizeof(x); })());		//OK : �L���v�`���Ȃ�
}


#pragma endregion ��������Ă݂���

#pragma region 
/**
 * mutable
 * �L���v�`�������ϐ��̓N���[�W���[�I�u�W�F�N�g�̃����o�ϐ��Ƃ݂Ȃ���A
 * �N���[�W���[�I�u�W�F�N�g�̊֐��Ăяo�����Z�q�́A�f�t�H���g��const�C�������
 * ���̂��߃R�s�[�L���v�`�������ϐ��������_���ŏ��������邱�Ƃ��ł��Ȃ�.
 */
void TestCode_6()
{
	//int rate = 2;
	//[rate](int x) -> int {return x * ++rate; }	//rate�ϐ������������邱�Ƃ��ł��Ȃ�

	/**
	 * �R�s�[�L���v�`�������ϐ����������������ꍇ�́A
	 * �����_���̃p�����[�^���X�g����mutable���L�q����. 
	*/

	int rate = 2;
	auto f = [rate](int x) mutable -> int {return x * ++rate; };
	cout << f(4) << endl;

}
#pragma endregion mutable

#pragma region 
/**
 * �N���[�W���[�I�u�W�F�N�g�͓����p�����[�^�^�Ɩ߂�l�^�̃V�O�j�`�������֐��|�C���^
 * �ɕϊ��ł���.
 */

void Foo(int(*fp)(int, int))
{
	int result = fp(2, 3);
	cout << result << endl;
}

void TestCode_7()
{
	/** �֐��|�C���^�������̊֐��Ƀ����_����n�� */
	Foo([](int a, int b) {return a + b; });
}

#pragma endregion �֐��|�C���^

#pragma region 

/**
 * �A���S���Y���̈����Ƃ��Ċ֐���n��.
 */
void TestCode_8()
{
	vector<int> v = { 1,2,3,4,5 };
	//�����̈�v����ŏ��̗v�f����������
	decltype(v)::iterator it = std::find_if(
											v.begin(),
											v.end(),
											[](int x) {return x % 2 == 0; }
											);

	//��������
	if (it != v.end())
	{
		int foundValue = *it;
		cout << foundValue << endl;
	}
}


/**
 * �����������̒ʒm�����������œn��.
 */

void Task(std::function<void()> onCompleteFunc)
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}

	//�����n���h�����Ăяo��
	onCompleteFunc();
}


void TestCode_9()
{
	//�������������Ă������ɌĂ΂��֐����w�肷��
	Task([] {cout << "Complete\n"; });
}



#pragma endregion ���p



int main()
{
	//TestCode_1();
	//TestCode_2();
	//TestCode_3();
	//int ret = TestCode_4()(2);
	//cout << ret << endl;
	//TestCode_5();
	//TestCode_6();
	//TestCode_7();
	TestCode_8();
	TestCode_9();
	
	return 0;
}