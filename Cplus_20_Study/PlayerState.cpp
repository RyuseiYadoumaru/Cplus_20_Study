#include "PlayerState.h"

void IdleState::EnterState()
{
	std::cout << "アイドルエンター\n";
	i = 0;
}

void IdleState::ExitState()
{
	std::cout << "アイドルイグジット\n";
}

void IdleState::Update()
{
	std::cout << "アイドル処理\n";
	i++;
	if (i >= 10)
		m_owner->GetStateMachine().ChangeState("MoveState");
}

void MoveState::EnterState()
{
	std::cout << "移動エンター処理\n";
	i = 0;
}

void MoveState::ExitState()
{
	std::cout << "移動イグジット処理\n";
}

void MoveState::Update()
{
	std::cout << "移動処理\n";
	i++;
	if (i >= 3)
		m_owner->GetStateMachine().ChangeState("JumpState");

}

void JumpState::EnterState()
{
	std::cout << "ジャンプエンター処理\n";
}

void JumpState::ExitState()
{
	std::cout << "ジャンプイグジット処理\n";
}

void JumpState::Update()
{
	std::cout << "ジャンプ処理\n";
}
