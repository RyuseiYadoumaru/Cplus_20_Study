class sample
{
public:
	int operator() (int n) const
	{
		return 2 * n;
	}
};


int main()
{

	//演算子のオーバーロード
	sample x;
	const auto e = x(10);
	int k = 3;

	//ラムダ式
	const auto y = [k](int n) {return k * n; };
	const auto m = y(10);

	return 0;

}