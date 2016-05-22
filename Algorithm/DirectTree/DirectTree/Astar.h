#pragma once
#include "MyPath.h"
class CAstar :
	public CMyPath
{
public:
	CAstar();
	~CAstar();
	int choose(int distance[], int distCurToTarget[], int maxNode, int visit[]);
	bool findPath(int sNode, int tNode, CMyMap map);
};

