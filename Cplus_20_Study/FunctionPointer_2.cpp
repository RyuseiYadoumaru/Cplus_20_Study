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
	//Player p1 = p;	//�R�s�[�R���X�g���N�^�̈׃G���[�ɂȂ�
	Player p2 = Player(); //���[�u�R���X�g���N�^�̈׃G���[�ɂȂ�Ȃ�


	//�����o�֐���Add�̊֐��A�h���X��ۑ�����
	//�������F���s����I�u�W�F�N�g
	//�������F�֐��̈���
	//��O�����F�֐��̈���
	//���񂾂ƁAp��Add�֐������s����
	std::function<int(Player&,int, int)> f_menber = &Player::Add;
	auto sum1 = f_menber(p, 1, 1);
	std::cout << sum1 << std::endl;


	//�֐���print_Mul�̃A�h���X��ۑ�
	std::function<void(int, int)> f_fun = print_Mul;
	f_fun(2, 2);

	//�����_���֐��̃A�h���X��ۑ�
	std::function< void(int) > f_lambda = [=](int i) { print_Mul(10, i); };
	f_lambda(10);

	//�o�C���h��p��Add�֐���ۑ�����
	std::function< void() > f_bind = std::bind(print_Mul, 4,4);
	f_bind();

	//�֐��I�u�W�F�N�g�̃A�h���X��ۑ�����
	std::function<int(int, int)> f_obj = Minas_obj();
	auto Minas = f_obj(10, 5);
	std::cout << Minas << std::endl;

	return 0;
 }