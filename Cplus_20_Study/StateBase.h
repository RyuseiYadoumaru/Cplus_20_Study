//*****************************************************************************
//* @file   StateBase.h
//* @brief  ステートの基底クラス
//* @note   
//* 
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#pragma once
#include <functional>

#define STATE_CLASS \
using StateBase::StateBase;

template<class FSMType>
class StateBase
{
	using MachinePtr = std::shared_ptr<FSMType>;

public:
	explicit StateBase(MachinePtr context) : m_context(context) {}
	~StateBase() = default;

public:
	virtual void EnterState() = 0;
	virtual void ExitState() = 0;
	virtual void Update() = 0;

protected:
	MachinePtr m_context;
};
