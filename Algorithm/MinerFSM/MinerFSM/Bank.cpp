#include "Bank.h"

CBank::CBank()
{
}
CBank::~CBank()
{
}

CBank * CBank::getInstance()
{
	static CBank instance;
	return &instance;
}
#include "MinerAI.h"
#include "Location.h"
#include "Mine.h"
#include "Home.h"
#include <iostream>
using namespace std;
void CBank::Enter(CMinerAI * pMiner)
{
	if (pMiner->getLocation() != BANK) {
		cout << pMiner->getName() << " : �������� ���ϴ�.." << endl;
		pMiner->changeLocation(BANK);
	}
}

void CBank::Execute(CMinerAI * pMiner)
{
	pMiner->addWealth(pMiner->getGold());
	pMiner->setGoldCarried(0);
	cout << pMiner->getName() << " : ���� �����߽��ϴ�.. " << endl;
	cout << pMiner->getName() << " : �� ������ �ݾ� : " << pMiner->getMoney() << endl;

	if (pMiner->isRich()) {
		cout << pMiner->getName() << " : ������ ���� �߱�... ������ ����.." << endl;
		pMiner->changeState(CHome::getInstance());
	}
	else {
		cout << pMiner->getName() << " : ���� ������... ���� �� ĳ����.." << endl;
		pMiner->changeState(CMine::getInstance());
	}
}

void CBank::Exit(CMinerAI * pMiner)
{
	cout << pMiner->getName() << " : ������ �����ϴ�.." << endl;
}
