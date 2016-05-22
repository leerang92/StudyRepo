#include "Mine.h"


CMine::CMine()
{
}

CMine::~CMine()
{
}

CMine * CMine::getInstance()
{
	static CMine instance;
	return &instance;
}

#include "MinerAI.h"
#include <iostream>
using namespace std;

void CMine::Enter(CMinerAI * pMiner)
{
	if (pMiner->getLocation() != MINE) {
		cout << pMiner->getName() << " : �ݱ����� �ɾ�ϴ�.." << endl;
		pMiner->changeLocation(MINE);
	}
}
#include "Bank.h"
#include "Saloon.h"
void CMine::Execute(CMinerAI * pMiner)
{
	cout << pMiner->getName() << " : ���� ĳ�� �ֽ��ϴ�.." << endl;
	cout << pMiner->getName() << " : �������� " << endl;
	pMiner->addGold(1);
	pMiner->increaseFatigue();

	if (pMiner->isPoketFull()) {
		cout << pMiner->getName() << " : ���� ���� ĺ��..." << endl;
		pMiner->changeState(CBank::getInstance());
	}
	if (pMiner->isThirsty()) {
		cout << pMiner->getName() << " : �����..." << endl;
		cout << pMiner->getName() << " : ���� ������.." << endl;
		cout << pMiner->getGold() << " : ������ ���� ���� �ؾ߰ڴ�.." << endl;
		pMiner->changeState(CSaloon::getInstance());
	}
}

void CMine::Exit(CMinerAI * pMiner)
{
	cout << pMiner->getName() << " : �ݱ��� �����ϴ�.." << endl;
}
