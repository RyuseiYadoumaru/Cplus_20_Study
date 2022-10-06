//*****************************************************************************
//* @file   Statemachine.h
//* @brief  �X�e�[�g�}�V�[���̊��N���X
//* @note   FSM�G(FiniteStateMachine) : �L����ԋ@�B
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
	 *  �X�e�[�g�o�^.
	 *
	 * !@param stateName : �X�e�[�g
	 * !@param state	 : �X�e�[�g�N���X
	 */
	void Register(StateType stateName, StatePtr state)
	{
		m_stateList.insert(std::make_pair(stateName, state));
		std::cout << "StateMachine�o�^\n";
	}

	/**
	 *  �X�e�[�g�؂�ւ�.
	 *
	 * !@param stateName : �؂�ւ��X�e�[�g
	 */
	void ChangeState(StateType stateName)
	{
		if (m_stateList.count(stateName) == 0){
			std::cout << "�X�e�[�g������܂���\n";
			return;
		}
		if (m_currentState != nullptr) m_currentState->ExitState();
		m_currentState = m_stateList[stateName];
		m_currentState->EnterState();
		std::cout << "StateMachine�؂�ւ�\n";
	}

	/**
	 *  �X�e�[�g�폜.
	 *
	 * !@param stateName : �폜�X�e�[�g
	 */
	void Remove(StateType stateName)
	{
		auto stateItr = m_stateList.find(stateName);
		if (stateItr == m_stateList.end()) return;
		m_stateList.erase(stateItr);
		std::cout << "StateMachine�폜\n";
	}

	/**
	 *  �X�e�[�g�S�폜.
	 *
	 */
	void AllRemove()
	{
		m_stateList.clear();
		std::cout << "StateMachine�S�폜\n";
	}

	/**
	 * �X�e�[�g�擾.
	 */
	StatePtr GetState(StateType state)
	{
		if (m_stateList.count(state) == 0) return nullptr;
		return m_stateList[state]; 
	}

public:
	// ������
	virtual void Initialize() = 0;

	// �X�V
	virtual void Update()
	{
		m_currentState->Update();
	}

	// �I������
	virtual void Finalize()
	{
		// �S�č폜����
		AllRemove();
	}
	
private:
	StateContainer m_stateList;
	StatePtr m_currentState = nullptr;
};