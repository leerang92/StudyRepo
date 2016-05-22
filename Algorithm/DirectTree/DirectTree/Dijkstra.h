#pragma once
#include "MyPath.h"
class CDijkstra :
	public CMyPath
{
public:
	CDijkstra();
	~CDijkstra();
	int choose(int distance[], int maxNode, int visit[]);
	bool findPath(int sNode, int tNode, CMyMap map);
};

