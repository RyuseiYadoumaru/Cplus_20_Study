#include "PlayerState.h"

void IdleState::EnterState()
{
	std::cout << "�A�C�h���G���^�[\n";
	i = 0;
}

void IdleState::ExitState()
{
	std::cout << "�A�C�h���C�O�W�b�g\n";
}

void IdleState::Update()
{
	std::cout << "�A�C�h������\n";
	i++;
	if (i >= 10)
		m_owner->GetStateMachine().ChangeState("MoveState");
}

void MoveState::EnterState()
{
	std::cout << "�ړ��G���^�[����\n";
	i = 0;
}

void MoveState::ExitState()
{
	std::cout << "�ړ��C�O�W�b�g����\n";
}

void MoveState::Update()
{
	std::cout << "�ړ�����\n";
	i++;
	if (i >= 3)
		m_owner->GetStateMachine().ChangeState("JumpState");

}

void JumpState::EnterState()
{
	std::cout << "�W�����v�G���^�[����\n";
}

void JumpState::ExitState()
{
	std::cout << "�W�����v�C�O�W�b�g����\n";
}

void JumpState::Update()
{
	std::cout << "�W�����v����\n";
}
