#include "Player.h"

void Player::Start()
{
	m_playerFSM.Initialize();
}

void Player::Update()
{
	m_playerFSM.Update();
}

void Player::End()
{
	m_playerFSM.Finalize();
}
