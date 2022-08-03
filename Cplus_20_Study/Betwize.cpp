//　ビット演算
//　https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361

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
	//2進数8ビット出力
	std::cout << std::bitset<8>(data) << std::endl;
	//8進数ビット出力
	std::cout << std::oct << data << std::endl;
	//10進数ビット出力
	std::cout << std::dec << data << std::endl;
	//16進数ビット出力
	std::cout << std::hex << data << std::endl;
}


int main()
{
	//全てのビットが0
	unsigned int bit = 0;
	Print<unsigned int>(bit);

	//0b0001
	bit++;
	Print<unsigned int>(bit);

	//2ビット左シフト
	bit <<= 2;
	Print<unsigned int>(bit);

	//1ビット右シフト
	bit >>= 1;
	Print<unsigned int>(bit);

	//下位4ビットでマスク AND
	unsigned int maskBit = bit & 0b1111;
	std::cout << "\nマスク\n";
	Print<unsigned int>(maskBit);

	//下位4ビットをOR
	unsigned int orBit = bit | 0b1111;
	std::cout << "\nOR\n";
	Print<unsigned int>(orBit);


	//ビットをNOT
	unsigned int notBit = ~bit;
	std::cout << "\nNOT\n";
	Print<unsigned int>(notBit);


	//4ビットをXOR
	unsigned int xorBit = bit ^ 0x0f;
	std::cout << "\n排他的論理和\n";
	Print <unsigned int>(xorBit);



	/****	条件分岐	****/
	unsigned int mask = 0xff;
	if (bit & (1 << 4));	//4ビット目にフラグがたっているか
	if (!(bit & (1 << 4))); //4ビット目にフラグがたっていない

	if (bit & mask);			//マスクの部分のどこが立っているか
	if ((bit & mask) == mask)	//マスクの部分のすべてのフラグがたっているか



	/****	フラグ操作	****/
	//4ビット目にフラグを立てる
		bit |= (1 << 4);
	Print<unsigned int>(bit);

	//4ビット目のフラグを折る
	bit &= ~(1 << 4);

	//ビットに何個のフラグがたっているか
	//__builtin_popcount(bit);

	std::cout << "\n8ビット目にフラグを立てたもの\n";
	Print<unsigned int>(bit | (1 << 8));

	std::cout << "\n4ビット目のフラグを折ったもの\n";
	Print<unsigned int>(bit & ~(1 << 4));

	std::cout << "\nマスクの部分をすべて立てる\n";
	std::cout << "\n\n";
	Print<unsigned int>(bit |= mask);

	std::cout << "\nマスク部分をまとめて消す\n";
	Print<unsigned int>(bit &= ~mask);

	std::cout << "\nマスク部分を取り出す\n";
	bit = 0xf1;
	Print<unsigned int>(bit & mask);


	for (int nowBit = 0; nowBit < (1 << 8); nowBit++)
	{
		//8ビットまで全探索
	}

}
