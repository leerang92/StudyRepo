#include "MinerAI.h"
#include <iostream>
#include <Windows.h>
#include "Home.h"
#include "Mine.h"
using namespace std;

void main() {

	CMinerAI miner("±¤ºÎ", CHome::getInstance());
	CMinerAI test("test", CMine::getInstance());

	for (int i = 0; i < 20; i++) {
		miner.update();
		test.update();
		Sleep(1000);
	}
}