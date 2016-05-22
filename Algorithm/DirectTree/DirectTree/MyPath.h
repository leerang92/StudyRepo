#pragma once
#include <stack>
#include "MyMap.h"
using namespace std;
class CMyPath
{
	stack<int> m_path;
public:
	CMyPath();
	~CMyPath();

	void pushNode(int node) { m_path.push(node); }
	void popNode() { m_path.pop(); }
	int getTopNode() { return m_path.top(); }

	void draw();
	virtual bool findPath(int sNode, int tNode, CMyMap map) = 0;
};

