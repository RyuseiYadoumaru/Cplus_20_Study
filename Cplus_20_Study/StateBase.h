//*****************************************************************************
//* @file   StateBase.h
//* @brief  ステートの基底クラス
//* @note   アニメーションやオブジェクトに対してステートを管理
//* @note   できるようなクラスをまとめる
//* 
//* @author YadoumaruRyusei
//* @date   October 2022
//*****************************************************************************
#pragma once
/**
 * ステートベース.
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




