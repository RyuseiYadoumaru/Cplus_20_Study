#pragma once

#include "StateMachine.h"
class PlayerFSM : public StateMachine<PlayerFSM>
{
	// StateMachine ����Čp������܂���
	virtual void Initialize() override;
};
