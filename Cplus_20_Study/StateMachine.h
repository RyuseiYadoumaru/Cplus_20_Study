//*****************************************************************************
//* @file   Statemachine.h
//* @brief  �X�e�[�g�}�V�[���̊��N���X
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
	 * ���݂̃X�e�[�g���X�V����.
	 */
	void Update()
	{
		m_currentState->Update();
	}

	/**
	 *  �X�e�[�g�o�^.
	 * 
	 * !@param stateName : �X�e�[�g
	 * !@param state	 : �X�e�[�g�N���X
	 */
	void Register(T stateName, StatePtr state)
	{
		m_stateList.insert(std::make_pair(stateName, state));
		std::cout << "StateMachine�o�^\n";
	}

	/**
	 *  �X�e�[�g�؂�ւ�.
	 * 
	 * !@param stateName : �؂�ւ��X�e�[�g
	 */
	void ChangeState(T stateName)
	{
		if(m_currentState != nullptr) m_currentState->ExitState();
		m_currentState = m_stateList[stateName];
		m_currentState->EnterState();
		std::cout << "StateMachine�؂�ւ�\n";

	}

	/**
	 *  �X�e�[�g�폜.
	 * 
	 * !@param stateName : �폜�X�e�[�g
	 */
	void Remove(T stateName)
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
		std::cout << "StateMachine�S�폜\n";
		m_stateList.clear();
	}

	/**
	 * �X�e�[�g�擾.
	 */
	StatePtr GetState(T state) { return m_stateList[state]; }

private:
	StateContainer m_stateList;
	StatePtr m_currentState = nullptr;
};