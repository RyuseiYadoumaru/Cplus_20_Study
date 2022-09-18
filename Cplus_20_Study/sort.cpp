#include <iostream>
#include <vector>
#include <algorithm>

class Test
{
public:
	Test() { id = allCnt + 1; }
	void Setparam(int set) { param = set; }
	int GetParam() { return param; }
	int getiD() { return id; }


private:
	int id;
	static int allCnt;
	int param;


};
int Test::allCnt = 0;

int main()
{
	std::vector<Test> t;

	for (int i = 0; i < 10; i++)
	{
		Test newtest;
		newtest.Setparam(i);
		t.push_back(newtest);
	}
	std::vector<int> test{ 3,5,6,1,0,6,3 };
	std::stable_sort(t.begin(), t.end(), [](Test test1, Test test2) {
		return test1.GetParam() > test2.GetParam();
		});
	for (auto s : t)
	{
		std::cout << s.GetParam() << std::endl;
	}

	return 0;
}
