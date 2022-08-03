#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <list>

#define SCREE_NLENGTH 20

//コンソールに出力するためのバッファ
class ScreenBuffer
{
public:
	union {
		char buffer[SCREE_NLENGTH * (SCREE_NLENGTH + 1) + 1];
		char buffer2[SCREE_NLENGTH][SCREE_NLENGTH + 1];
	};
	ScreenBuffer()
	{
		Clear();
	}

	void Clear()
	{
		//Bufferをスペースでクリア
		for (int i = 0; i < SCREE_NLENGTH * (SCREE_NLENGTH + 1); i++)
		{
			buffer[i] = ' ';
		}
		//行の終わりに改行入れる
		for (int i = 0; i < SCREE_NLENGTH; i++)
			buffer2[i][SCREE_NLENGTH] = '\n';

		//全ての終わりにNULL文字
		buffer[SCREE_NLENGTH * (SCREE_NLENGTH + 1)] = '\0';
	}
};

class InputData
{
	static char Buffer;
public:
	static void Update()
	{
		if (_kbhit()) {
			Buffer = _getch();
		}
	}
	static bool KeyCheck(char key)
	{
		if (Buffer == key)
			return true;
		return false;
	}
};

extern ScreenBuffer g_ScreenBuffer;