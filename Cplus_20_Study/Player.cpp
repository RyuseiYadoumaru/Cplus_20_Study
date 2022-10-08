#include "Player.h"
#include "PlayerState.h"

void Player::Start()
{
	m_stateMachine.Register("IdleState", std::make_shared<IdleState>(this));
	m_stateMachine.Register("MoveState", std::make_shared<MoveState>(this));
	m_stateMachine.Register("JumpState", std::make_shared<JumpState>(this));
	m_stateMachine.ChangeState("IdleState");
}

void Player::Update()
{
	m_stateMachine.StateUpdate();
}

void Player::End()
{
}
