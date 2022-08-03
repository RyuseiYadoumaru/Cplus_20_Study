//�@�r�b�g���Z
//�@https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361

#include <utility>
#include <concepts>
#include <string>
#include <vector>
#include <concepts>
#include <iostream>
#include <bitset>


template <std::unsigned_integral T >
void Print(T data)
{
	//2�i��8�r�b�g�o��
	std::cout << std::bitset<8>(data) << std::endl;
	//8�i���r�b�g�o��
	std::cout << std::oct << data << std::endl;
	//10�i���r�b�g�o��
	std::cout << std::dec << data << std::endl;
	//16�i���r�b�g�o��
	std::cout << std::hex << data << std::endl;
}


int main()
{
	//�S�Ẵr�b�g��0
	unsigned int bit = 0;
	Print<unsigned int>(bit);

	//0b0001
	bit++;
	Print<unsigned int>(bit);

	//2�r�b�g���V�t�g
	bit <<= 2;
	Print<unsigned int>(bit);

	//1�r�b�g�E�V�t�g
	bit >>= 1;
	Print<unsigned int>(bit);

	//����4�r�b�g�Ń}�X�N AND
	unsigned int maskBit = bit & 0b1111;
	std::cout << "\n�}�X�N\n";
	Print<unsigned int>(maskBit);

	//����4�r�b�g��OR
	unsigned int orBit = bit | 0b1111;
	std::cout << "\nOR\n";
	Print<unsigned int>(orBit);


	//�r�b�g��NOT
	unsigned int notBit = ~bit;
	std::cout << "\nNOT\n";
	Print<unsigned int>(notBit);


	//4�r�b�g��XOR
	unsigned int xorBit = bit ^ 0x0f;
	std::cout << "\n�r���I�_���a\n";
	Print <unsigned int>(xorBit);



	/****	��������	****/
	unsigned int mask = 0xff;
	if (bit & (1 << 4));	//4�r�b�g�ڂɃt���O�������Ă��邩
	if (!(bit & (1 << 4))); //4�r�b�g�ڂɃt���O�������Ă��Ȃ�

	if (bit & mask);			//�}�X�N�̕����̂ǂ��������Ă��邩
	if ((bit & mask) == mask)	//�}�X�N�̕����̂��ׂẴt���O�������Ă��邩



	/****	�t���O����	****/
	//4�r�b�g�ڂɃt���O�𗧂Ă�
		bit |= (1 << 4);
	Print<unsigned int>(bit);

	//4�r�b�g�ڂ̃t���O��܂�
	bit &= ~(1 << 4);

	//�r�b�g�ɉ��̃t���O�������Ă��邩
	//__builtin_popcount(bit);

	std::cout << "\n8�r�b�g�ڂɃt���O�𗧂Ă�����\n";
	Print<unsigned int>(bit | (1 << 8));

	std::cout << "\n4�r�b�g�ڂ̃t���O��܂�������\n";
	Print<unsigned int>(bit & ~(1 << 4));

	std::cout << "\n�}�X�N�̕��������ׂė��Ă�\n";
	std::cout << "\n\n";
	Print<unsigned int>(bit |= mask);

	std::cout << "\n�}�X�N�������܂Ƃ߂ď���\n";
	Print<unsigned int>(bit &= ~mask);

	std::cout << "\n�}�X�N���������o��\n";
	bit = 0xf1;
	Print<unsigned int>(bit & mask);


	for (int nowBit = 0; nowBit < (1 << 8); nowBit++)
	{
		//8�r�b�g�܂őS�T��
	}

}
