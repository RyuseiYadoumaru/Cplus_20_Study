//*****************************************************************************
//* @file   main.cpp
//* @brief  ステートマシーンの勉強です。
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
			std::cout << "移動ステート初期化\n";
			testFunc();
		}
		virtual void ExitState() override
		{
			std::cout << "移動ステート終了\n";

		}
		virtual void Update() override
		{
			std::cout << "移動ステート更新\n";

		}
	};

	class JumpState : public StateBase
	{
	public:
		virtual void EnterState() override
		{
			std::cout << "ジャンプステート初期化\n";
		}
		virtual void ExitState() override
		{
			std::cout << "ジャンプステート終了\n";

		}
		virtual void Update() override
		{
			std::cout << "ジャンプステート更新\n";

		}
	};

	class IdleState : public StateBase
	{
	public:
		virtual void EnterState() override
		{
			std::cout << "待機ステート初期化\n";
		}
		virtual void ExitState() override
		{
			std::cout << "待機ステート終了\n";

		}
		virtual void Update() override
		{
			std::cout << "待機ステート更新\n";

		}
	};

	class DeathState : public  StateBase
	{
	public:
		virtual void EnterState() override
		{
			std::cout << "死亡ステート初期化\n";
		}
		virtual void ExitState() override
		{
			std::cout << "死亡ステート終了\n";

		}
		virtual void Update() override
		{
			std::cout << "死亡ステート更新\n";

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
			std::cout << "関数ポインタでプレイヤーの処理をするよ (pos): " << pos << std::endl;
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
		std::cout << "関数ポインタでプレイヤーの処理をするよ (pos): " << pos << std::endl;
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
