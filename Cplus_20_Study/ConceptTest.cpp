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


	//リクエストあり
	//RunFunc_1<Test_1>(t1);
	//RunFunc_1<Test_2>(t2);
	//RunFunc_1<Test_3>(t3);

	//リクエストなし
	//RunFunc_2<Test_1>(t1);
	//RunFunc_2<Test_2>(t2);
	//RunFunc_2<Test_3>(t3);


	//リクエストありだが引数がポインタ
	//RunFunc_3<Test_1>(new Test_1);
	//RunFunc_3<Test_2>(new Test_2);
	//RunFunc_3<Test_3>(new Test_3);


	//リクエストを使用すると確実な型を指定することが可能だが、
	//指定の仕方によってはアドレス渡しと参照渡しの違いでもはじかれるので、
	//汎用的にしたい場合はオーバーライドする必要がある
}
