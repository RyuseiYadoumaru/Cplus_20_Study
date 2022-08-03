#include <functional>
#include <iostream>

class Player 
{
public:
	Player(const Player&) = delete;
	~Player() = default;
	Player() = default;
	Player(Player&&) = default;

public:
	int Add(int a, int b) { return a + b; }

};

struct Minas_obj
{
	int operator()(int a, int b) { return a - b; }
};

void print_Mul(int a, int b) { printf("%d\n", a * b); }


int main()
{
	Player p;
	//Player p1 = p;	//コピーコンストラクタの為エラーになる
	Player p2 = Player(); //ムーブコンストラクタの為エラーにならない


	//メンバ関数のAddの関数アドレスを保存する
	//第一引数：実行するオブジェクト
	//第二引数：関数の引数
	//第三引数：関数の引数
	//今回だと、pのAdd関数を実行する
	std::function<int(Player&,int, int)> f_menber = &Player::Add;
	auto sum1 = f_menber(p, 1, 1);
	std::cout << sum1 << std::endl;


	//関数のprint_Mulのアドレスを保存
	std::function<void(int, int)> f_fun = print_Mul;
	f_fun(2, 2);

	//ラムダ式関数のアドレスを保存
	std::function< void(int) > f_lambda = [=](int i) { print_Mul(10, i); };
	f_lambda(10);

	//バインドでpのAdd関数を保存する
	std::function< void() > f_bind = std::bind(print_Mul, 4,4);
	f_bind();

	//関数オブジェクトのアドレスを保存する
	std::function<int(int, int)> f_obj = Minas_obj();
	auto Minas = f_obj(10, 5);
	std::cout << Minas << std::endl;

	return 0;
 }