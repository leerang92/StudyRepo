#pragma once

#define kMaxFatigue	5
#define kMaxMoney	3
#define kMaxRest	5
#define kMaxNugget	5
#define kMaxThirst	10

class CMinerAI;

class CState
{
public:

	CState()
	{
	}

	~CState()
	{
	}

	virtual void Enter(CMinerAI *) = 0;
	virtual void Execute(CMinerAI *) = 0;
	virtual void Exit(CMinerAI *) = 0;
};

