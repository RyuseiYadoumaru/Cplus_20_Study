#pragma once
#include "PlayerFSM.h"

class Player
{
public:
	void Start();
	void Update();
	void End();

private:
	PlayerFSM m_playerFSM;
};
