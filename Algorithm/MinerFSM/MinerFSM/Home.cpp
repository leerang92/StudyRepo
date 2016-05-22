#include "Home.h"

CHome::CHome()
{
}


CHome::~CHome()
{
}

CHome * CHome::getInstance()
{
	static CHome instance;
	return &instance;
}
#include "Location.h"
#include "MinerAI.h"

#include <iostream>
using namespace std;
void CHome::Enter(CMinerAI *pMiner)
{
	if (pMiner->getLocation() != HOME) {
		cout << pMiner->getLocation() << " : ������ �ɾ�ϴ�.." << endl;
		pMiner->changeLocation(HOME);
	}
}
#include "Mine.h"
void CHome::Execute(CMinerAI *pMiner)
{
	if (!pMiner->isFatigue()) {
		cout << pMiner->getName() << " : �� ������.. ���Ϸ� ����" << endl;
		pMiner->changeState(CMine::getInstance());
	}
	else {
		pMiner->decreaseFatigue();
		cout << pMiner->getName() << " : ������... " << endl;
	}
}
void CHome::Exit(CMinerAI *pMiner)
{
	cout << pMiner->getName() << " : ���� �����ϴ�.." << endl;
}
