#include <iostream>
#include "MyQueue.h"
using namespace std;

void main() {

	CMyQueue<int> q;

	for (int i = 0; i < 10; i++)
		q.enQueue(i*2);
	
	for (int i = 0; !q.isEmpty(); i++)
		cout << q.deQueue() << endl;
}