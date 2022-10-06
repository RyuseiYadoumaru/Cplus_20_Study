#pragma once
#include "StateBase.h"
#include "PlayerFSM.h"

class IdleState : public StateBase<PlayerFSM>
{
public:
	STATE_CLASS

public:
	// StateBase を介して継承されました
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void Update() override;
};
