#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

class Foo
{
	int a = 0;
	int b = 0;
};

struct  test
{
	int a = 0;
	int b = 0;
};

enum class Enum
{
	one,
	two
};

#define CLASS_NAME(CLASS) typeid(CLASS).name();


int main()
{
	Foo obj_1;
	string name_class = typeid(obj_1).name();
	cout << name_class << endl;

	test obj_2;
	string name_struct = typeid(obj_2).name();
	cout << name_struct << endl;

	Enum obj_3;
	string name_enumclass = typeid(obj_3).name();
	cout << name_enumclass << endl;

	string name = CLASS_NAME(string);
	cout << name << "\n";

	return 0;
}