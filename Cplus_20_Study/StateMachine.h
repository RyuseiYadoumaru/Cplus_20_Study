//*****************************************************************************
//* @file   Statemachine.h
//* @brief  ステートマシーンの基底クラス
//* @note   
//* 
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#pragma once
#include "StateBase.h"
#include <unordered_map>
#include <memory>
#include <iostream>

template<class T>
class StateMachine
{
	using StatePtr = std::shared_ptr<StateBase>;
	using StateContainer = std::unordered_map<T, StatePtr>;
	friend StateBase;

public:
	StateMachine() = default;
	~StateMachine() = default;

public:

	/**
	 * 現在のステートを更新する.
	 */
	void Update()
	{
		m_currentState->Update();
	}

	/**
	 *  ステート登録.
	 * 
	 * !@param stateName : ステート
	 * !@param state	 : ステートクラス
	 */
	void Register(T stateName, StatePtr state)
	{
		m_stateList.insert(std::make_pair(stateName, state));
		std::cout << "StateMachine登録\n";
	}

	/**
	 *  ステート切り替え.
	 * 
	 * !@param stateName : 切り替えステート
	 */
	void ChangeState(T stateName)
	{
		if(m_currentState != nullptr) m_currentState->ExitState();
		m_currentState = m_stateList[stateName];
		m_currentState->EnterState();
		std::cout << "StateMachine切り替え\n";

	}

	/**
	 *  ステート削除.
	 * 
	 * !@param stateName : 削除ステート
	 */
	void Remove(T stateName)
	{
		auto stateItr = m_stateList.find(stateName);
		if (stateItr == m_stateList.end()) return;
		m_stateList.erase(stateItr);
		std::cout << "StateMachine削除\n";
	}

	/**
	 *  ステート全削除.
	 * 
	 */
	void AllRemove()
	{
		std::cout << "StateMachine全削除\n";
		m_stateList.clear();
	}

	/**
	 * ステート取得.
	 */
	StatePtr GetState(T state) { return m_stateList[state]; }

private:
	StateContainer m_stateList;
	StatePtr m_currentState = nullptr;
};