//*****************************************************************************
//* @file   StateBase.h
//* @brief  �X�e�[�g�̊��N���X
//* @note   �A�j���[�V������I�u�W�F�N�g�ɑ΂��ăX�e�[�g���Ǘ�
//* @note   �ł���悤�ȃN���X���܂Ƃ߂�
//* 
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#pragma once
/**
 * �X�e�[�g�x�[�X.
 */
class StateBase
{
public:
	StateBase() = default;
	~StateBase() = default;

public:
	virtual void EnterState()	= 0;
	virtual void ExitState()	= 0;
	virtual void Update()		= 0;
};




