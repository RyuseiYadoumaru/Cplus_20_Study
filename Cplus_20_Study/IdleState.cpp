#include "IdleState.h"
#include <iostream>

void IdleState::EnterState()
{
	std::cout << "アイドル初期化\n";
}

void IdleState::ExitState()
{
	std::cout << "アイドル終了\n";
}

void IdleState::Update()
{
	std::cout << "アイドル更新\n";
}
