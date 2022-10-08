#pragma once
#include "StateMachine.h"

class Player
{
public:
	void Start();
	void Update();
	void End();

	StateMachine& GetStateMachine() noexcept { return m_stateMachine; }

private:
	friend class PlayerState;

	StateMachine m_stateMachine;
};