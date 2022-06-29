//	Concepts�F�R���Z�v�g
//	C++20���瓱���B�e���v���[�g�p�����[�^�𐧖�
//	https://cpprefjp.github.io/lang/cpp20/concepts.html

#include <type_traits>
#include <iterator>
#include <utility>
#include <concepts>
#include <string>
#include <vector>
#include <concepts>
#include <cmath>
#include <limits>
#include <cassert>
#include <iostream>


//�����o�֐��������Ă��邩�v�����鐧��̒�`��
#pragma region requires
//�����o�֐�Draw()�������Ƃ�v������
template <class T>
concept Drawble = requires(T & x)
{
	x.Draw();
};


//�e���v���[�g�p�����[�^T���R���Z�v�gDrawble�Ő���
//Drawble�̗v���𖞂����Ȃ��^���n���ꂽ�ꍇ�̓G���[�ɂȂ�
template<Drawble T>
void Func(T& x)
{
	x.Draw();
}

//Draw����
class GameObject
{
public:
	void Draw() {}
};

//Draw�p��
class Player : public GameObject
{

};

//Draw��Private
class GameObject_private
{
private:
	void Draw() {}
};

//Draw�Ȃ�
class System
{
public:
	void SetUp() {}
};
#pragma endregion �����o�֐��𐧌�����




//�^�ɑ΂���v���̏W���ł���R���Z�v�g���`����
//�^���ǂ̂悤�ȓ��������̂��i�����^�H���������^�H�j(==�Ŕ�r�\���A<�ŏ����t�����邩)
//�^�ɑ΂��Ăǂ̂悤�ȑ��삪�ł���̂��i�����o�֐��̌Ăяo���A���̌^�Ƃ̉��Z�j
#pragma region 

//���łɗp�ӂ���Ă���萔�������b�v���ăR���Z�v�g���`
template <class T>
concept Integral = std::is_integral_v<T>;

//2�ȏ�̃e���v���[�g�����R���Z�v�g
template<class T, class U>
concept EqualityComparable = requires(T a, U b)
{
	//���̖߂�l�^�𐧖�B���ږ߂�l�^�͎w��ł��Ȃ�
	{a == b} -> std::convertible_to<bool>;
};

//�߂�l�^�̗v���ɂ͒��ڂ̌^�ł͂Ȃ��R���Z�v�g���g����
template <class T, class U>
concept Addable = requires(T a, U b)
{
	//���Z���ʂƂ��Č^T�ƌ^U�̋��ʂ̌^���ς��邱��
	{a + b} -> std::common_with<T>;
};

//�Z�~�R������؂�ŕ����v����񋓂ł���
template <class T>
concept SequenceContainer = requires(T c)
{
	//�^T�������o�^�Ƃ���size_type�������Ă��邱��
	typename T::size_type;

	//�^T�̃I�u�W�F�N�g�ɑ΂��ē���̃����o�֐����Ăяo����
	{c.size()} -> std::convertible_to<typename T::size_type>;

	//�񃁃��o�֐��̌Ăяo�����v���ł���
	{std::size(c)} -> std::convertible_to<typename T::size_type>;

	typename T::value_type;
	c.push_back(std::declval<typename T::value_type>());

};
#pragma endregion �^�̐���




//static_assert�ƃR���Z�v�g�̈Ⴂ
//static_assert	�F�v���𖞂����Ȃ��ꍇ�ɑ����ɃR���p�C���G���[�ɂȂ�
//�R���Z�v�g	�F�v���𖞂����Ȃ��ꍇ�ɂق��̌���T��
//�֐��e���v���[�g�̃I�[�o�[���[�h�A�N���X�e���v���[�g�A�ϐ��e���v���[�g�̓��ꉻ�Ɏg�p����B
#pragma region 

//���l�̓��l��r���s���֐��𐮐��^�����������^���ŃI�[�o�[���[�h����
template <std::integral T>
bool equal(T a, T b)
{
	return a == b;
}

template <std::floating_point T>
bool equal(T a, T b)
{
	//std::numeric_limits<T>::epsilon()�F���������_�̔�r�̂��߂Ɍv�Z�덷�����e����𓙒l��r
	return std::abs(a - b) <= std::numeric_limits<T>::epsilon();
}

//�ϐ��e���v���[�g�𐮐��^�����������^���œ��ꉻ����
//�N���X�e���v���[�g�ł��������Ƃ��ł���
template<class T>
constexpr T pi;

template <std::floating_point T>
constexpr T pi<T> = static_cast<T>(3.141592653589793);

template <std::integral T>
constexpr T pi<T> = static_cast<T>(3);



#pragma endregion �R���Z�v�g�̃I�[�o�[���[�h�Ɠ��ꉻ



int main()
{
	//�����o�֐��̐���
	{

		GameObject obj;
		Func(obj);

		//DrawPrivate
		//GameObject_private obj_DrawPrivate;
		//Func(obj_DrawPrivate);

		Player player;
		Func(player);

		//NotDrawFunction
		//System sys;
		//Func(sys);
	}

	//�R���Z�v�g��bool�萔���Ƃ��Ďg�p�ł���
	{
		static_assert(Integral<int>);
		static_assert(EqualityComparable<int, int>);
		static_assert(Addable<std::string, char>);
		static_assert(SequenceContainer<std::vector<int>>);
	}

	//�I�[�o�[���[�h�Ɠ��ꉻ���܂����B
	{
		assert(equal(1 + 2, 3));

		//�v�Z�덷�ɂ����0.1 + 0.2 == 0.3�ɂ͂Ȃ�Ȃ���
		//�덷�����e���邱�Ƃœ��l�ƌ��Ȃ��B
		//(0.1 + 0.2 �� 0.30000000000000004 �̂悤�Ȓl�ɂȂ�)
		assert(equal(0.1 + 0.2, 0.3));

		std::cout << pi<double> << std::endl; // 3.14159
		std::cout << pi<int> << std::endl;    // 3
	}

	return 0;
}