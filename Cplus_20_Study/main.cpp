//*****************************************************************************
//* @file   main.cpp
//* @brief  ステートマシーンの勉強です。
//* @note   
//* 
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#include "Player.h"
#include <Windows.h>

BYTE g_byte[256] = {0};
int i = 0;

int main()
{
	Player player;
	player.Start();
	do
	{
		GetKeyboardState(g_byte);
		player.Update();
		Sleep(1000);
		i++;
	} while ((g_byte[VK_ESCAPE] & 0x80) == false);

	player.End();
	getchar();
	return 0;
}
