#include "MinerAI.h"

CMinerAI::CMinerAI()
{
}


CMinerAI::~CMinerAI()
{
}

void CMinerAI::update()
{
	m_thirst++;
	if (m_curState)
		m_curState->Execute(this);
}
void CMinerAI::changeState(CState *newState)
{
	m_curState->Exit(this);
	m_curState = newState;
	m_curState->Enter(this);
}
