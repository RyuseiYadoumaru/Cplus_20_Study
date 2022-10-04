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

class StateBase
{
public:
	StateBase() = default;
	~StateBase() = default;

public:
	virtual void EnterState() = 0;
	virtual void ExitState() = 0;
	virtual void Update() = 0;

public:
	void SetFunc(std::function<void()> test) { testFunc = test; }

protected:
	std::function<void()> testFunc;

private:

};
