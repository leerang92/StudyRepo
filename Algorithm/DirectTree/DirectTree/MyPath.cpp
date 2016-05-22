#include "MyPath.h"
#include <iostream>
using namespace std;


CMyPath::CMyPath()
{
}
CMyPath::~CMyPath()
{
}

void CMyPath::draw()
{
	do {
		cout << getTopNode() << " - ";
		popNode();
	} while (!m_path.empty());
	cout << endl;
}
