#pragma once

#include "StateMachine.h"
class PlayerFSM : public StateMachine<PlayerFSM>
{
	// StateMachine を介して継承されました
	virtual void Initialize() override;
};
