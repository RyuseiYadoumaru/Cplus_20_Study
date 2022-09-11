template <class T>
concept TYPE = requires(T& t)
{
	t.Run();
};


class Test_1
{
public:
	void Run() { return; }
};

class Test_2
{
public:
	void Running() { return; }
};

class Test_3
{
private:
	void Run() { return; }
};


template<TYPE T>
void RunFunc_1(T t)
{
	t.Run();
}

template<class T>
void RunFunc_2(T t)
{
	t.Run();
}

template<TYPE T>
void RunFunc_3(T* t)
{
	t.Run();
}


int main()
{
	Test_1 t1;
	Test_2 t2;
	Test_3 t3;


	//���N�G�X�g����
	//RunFunc_1<Test_1>(t1);
	//RunFunc_1<Test_2>(t2);
	//RunFunc_1<Test_3>(t3);

	//���N�G�X�g�Ȃ�
	//RunFunc_2<Test_1>(t1);
	//RunFunc_2<Test_2>(t2);
	//RunFunc_2<Test_3>(t3);


	//���N�G�X�g���肾���������|�C���^
	//RunFunc_3<Test_1>(new Test_1);
	//RunFunc_3<Test_2>(new Test_2);
	//RunFunc_3<Test_3>(new Test_3);


	//���N�G�X�g���g�p����Ɗm���Ȍ^���w�肷�邱�Ƃ��\�����A
	//�w��̎d���ɂ���Ă̓A�h���X�n���ƎQ�Ɠn���̈Ⴂ�ł��͂������̂ŁA
	//�ėp�I�ɂ������ꍇ�̓I�[�o�[���C�h����K�v������
}
