#include "PlayerFSM.h"
#include "IdleState.h"

void PlayerFSM::Initialize()
{
	Register("Idle", std::make_shared<IdleState>(this));
}
