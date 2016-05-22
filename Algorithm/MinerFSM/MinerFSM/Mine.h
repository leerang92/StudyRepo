#pragma once
#include "State.h"
#include "Location.h"
class CMine : public CState
{
	CMine();
public:
	~CMine();
	static CMine *getInstance();
	void Enter(CMinerAI *pMiner);
	void Execute(CMinerAI *pMiner);
	void Exit(CMinerAI *pMiner);
};

