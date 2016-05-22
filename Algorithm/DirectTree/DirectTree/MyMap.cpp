#include "MyMap.h"



CMyMap::CMyMap()
{
}


CMyMap::~CMyMap()
{
}

#include <iostream>
using namespace std;

void CMyMap::setMap(int ** map)
{
	for (int h = 0; h < m_height; h++) {
		for (int w = 0; w < m_width; w++) {
			m_map[h][w] = map[h][w];
		}
	}
}

void CMyMap::draw()
{
	for (int h = 0; h < m_height; h++) {
		for (int w = 0; w < m_width; w++) {
			cout << m_map[h][w] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
