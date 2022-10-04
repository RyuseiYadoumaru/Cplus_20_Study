//*****************************************************************************
//* @file   main.cpp
//* @brief  �X�e�[�g�}�V�[���̕׋��ł��B
//* @note   
//* 
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#include "StateMachine.h"
#include <Windows.h>
BYTE g_byte[256] = {0};
int i = 0;

class Player
{
	enum class State
	{
		Idle,
		Move,
		Jump,
		Death
	};

	class MoveState : public StateBase
	{
	public:
		virtual void EnterState() override
		{
			std::cout << "�ړ��X�e�[�g������\n";
			testFunc();
		}
		virtual void ExitState() override
		{
			std::cout << "�ړ��X�e�[�g�I��\n";

		}
		virtual void Update() override
		{
			std::cout << "�ړ��X�e�[�g�X�V\n";

		}
	};

	class JumpState : public StateBase
	{
	public:
		virtual void EnterState() override
		{
			std::cout << "�W�����v�X�e�[�g������\n";
		}
		virtual void ExitState() override
		{
			std::cout << "�W�����v�X�e�[�g�I��\n";

		}
		virtual void Update() override
		{
			std::cout << "�W�����v�X�e�[�g�X�V\n";

		}
	};

	class IdleState : public StateBase
	{
	public:
		virtual void EnterState() override
		{
			std::cout << "�ҋ@�X�e�[�g������\n";
		}
		virtual void ExitState() override
		{
			std::cout << "�ҋ@�X�e�[�g�I��\n";

		}
		virtual void Update() override
		{
			std::cout << "�ҋ@�X�e�[�g�X�V\n";

		}
	};

	class DeathState : public  StateBase
	{
	public:
		virtual void EnterState() override
		{
			std::cout << "���S�X�e�[�g������\n";
		}
		virtual void ExitState() override
		{
			std::cout << "���S�X�e�[�g�I��\n";

		}
		virtual void Update() override
		{
			std::cout << "���S�X�e�[�g�X�V\n";

		}
	};

public:
	void Start()
	{
		m_playerFSM.Register(Player::State::Move, std::make_shared<Player::MoveState>());
		m_playerFSM.Register(Player::State::Jump, std::make_shared<Player::JumpState>());
		m_playerFSM.Register(Player::State::Idle, std::make_shared<Player::IdleState>());
		m_playerFSM.Register(Player::State::Death, std::make_shared<Player::DeathState>());
		m_playerFSM.ChangeState(Player::State::Idle);
		m_playerFSM.GetState(Player::State::Move)->SetFunc([this] {
			Move();
			pos = 100;
			std::cout << "�֐��|�C���^�Ńv���C���[�̏���������� (pos): " << pos << std::endl;
			});
	}
	void Update()
	{
		m_playerFSM.Update();
		if ((i == 5))
		{
			m_playerFSM.ChangeState(Player::State::Move);
		}
	}
	void End()
	{
		m_playerFSM.AllRemove();
	}

private:
	int pos = 0;
	StateMachine<Player::State> m_playerFSM;
	void Move(){
		pos = 100;
		std::cout << "�֐��|�C���^�Ńv���C���[�̏���������� (pos): " << pos << std::endl;
	}
};

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
