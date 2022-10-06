//*****************************************************************************
//* @file   Statemachine.h
//* @brief  ステートマシーンの基底クラス
//* @note   FSM；(FiniteStateMachine) : 有限状態機械
//* 
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#pragma once
#include "StateBase.h"
#include <unordered_map>
#include <memory>
#include <iostream>

template<class FSMType>
class StateMachine
{
protected:
	using StatePtr = std::shared_ptr<StateBase<FSMType>>;
	using StateType = std::string;
	using StateContainer = std::unordered_map<StateType, StatePtr>;

public:
	StateMachine() = default;
	~StateMachine() = default;

public:
	/**
	 *  ステート登録.
	 *
	 * !@param stateName : ステート
	 * !@param state	 : ステートクラス
	 */
	void Register(StateType stateName, StatePtr state)
	{
		m_stateList.insert(std::make_pair(stateName, state));
		std::cout << "StateMachine登録\n";
	}

	/**
	 *  ステート切り替え.
	 *
	 * !@param stateName : 切り替えステート
	 */
	void ChangeState(StateType stateName)
	{
		if (m_stateList.count(stateName) == 0){
			std::cout << "ステートがありません\n";
			return;
		}
		if (m_currentState != nullptr) m_currentState->ExitState();
		m_currentState = m_stateList[stateName];
		m_currentState->EnterState();
		std::cout << "StateMachine切り替え\n";
	}

	/**
	 *  ステート削除.
	 *
	 * !@param stateName : 削除ステート
	 */
	void Remove(StateType stateName)
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
		m_stateList.clear();
		std::cout << "StateMachine全削除\n";
	}

	/**
	 * ステート取得.
	 */
	StatePtr GetState(StateType state)
	{
		if (m_stateList.count(state) == 0) return nullptr;
		return m_stateList[state]; 
	}

public:
	// 初期化
	virtual void Initialize() = 0;

	// 更新
	virtual void Update()
	{
		m_currentState->Update();
	}

	// 終了処理
	virtual void Finalize()
	{
		// 全て削除する
		AllRemove();
	}
	
private:
	StateContainer m_stateList;
	StatePtr m_currentState = nullptr;
};