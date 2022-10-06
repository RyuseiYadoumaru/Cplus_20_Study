#pragma once
#include "StateBase.h"
#include "PlayerFSM.h"

class IdleState : public StateBase<PlayerFSM>
{
public:
	STATE_CLASS

public:
	// StateBase ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void Update() override;
};
