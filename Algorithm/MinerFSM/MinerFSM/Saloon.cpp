#include "Saloon.h"

CSaloon::CSaloon()
{
}


CSaloon::~CSaloon()
{
}

CSaloon * CSaloon::getInstance()
{
	static CSaloon instance;
	return &instance;
}
#include "Location.h"
#include "MinerAI.h"
#include "Mine.h"
#include <iostream>
using namespace std;

void CSaloon::Enter(CMinerAI * pMiner)
{
	if (pMiner->getLocation() != SALOON) {
		pMiner->changeLocation(SALOON);
		cout << pMiner->getName() << " : �������� ���ϴ�.." << endl;
	}
}

void CSaloon::Execute(CMinerAI * pMiner)
{
	if (pMiner->isThirsty()) {
		pMiner->drinkWhiskey();
		cout << pMiner->getName() << " : ���� ����..." << endl;
		cout << pMiner->getName() << " : �� ���̴�..." << endl;
		pMiner->changeState(CMine::getInstance());
	}
}

void CSaloon::Exit(CMinerAI * pMiner)
{
	cout << pMiner->getName() << " : ������ �����ϴ�.." << endl;
}
