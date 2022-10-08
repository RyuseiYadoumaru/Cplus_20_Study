//******************************************************************************
//* @file   PlayerState.h
//* @brief  プレイヤーのステート
//* @note   
//* 
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#pragma once
#include "StateBase.h"
#include "Player.h"

/**
 * プレイヤーステート.
 */
#define PLAYER_STATE PlayerState::PlayerState;

class PlayerState : public StateBase
{
public:
	explicit PlayerState(Player* owner) : m_owner(owner) {}

protected:
	Player* m_owner;

};


class IdleState : public PlayerState
{
public:
	PLAYER_STATE;

public:
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void Update() override;

private:
	int i = 0;
};


class MoveState : public PlayerState
{
public:
	PLAYER_STATE;

public:
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void Update() override;

private:
	int i = 0;
};

class JumpState : public PlayerState
{
public:
	PLAYER_STATE;

public:
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void Update() override;
};
