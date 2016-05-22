#include "Astar.h"



CAstar::CAstar()
{
}


CAstar::~CAstar()
{
}

enum { UNVISIT, VISITED };
#include <iostream>
using namespace std;

int CAstar::choose(int distance[], int distCurToTarget[], int maxNode, int visit[])
{
	int curNode;
	int minCost, minNode;

	minCost = 9999;
	minNode = -1;
	//비용이 가장 적은 경로 찾아 리턴함.
	//Dijkstra와 다른 점은 distCurToTarget이 추가되었다.
	for (curNode = 0; curNode < maxNode; curNode++) {
		if (!visit[curNode] && distance[curNode] + distCurToTarget[curNode] < minCost) {
			minCost = distance[curNode] + distCurToTarget[curNode];
			minNode = curNode;
		}
	}
	return minNode;
}

//sNode : start,	tNode : targetNode
bool CAstar::findPath(int sNode, int tNode, CMyMap map)
{
	bool bFound = false;
	int MaxNode = map.getWidth();		// 노드의 총 갯수
	int *parent = new int[MaxNode];		// 현재 노드의 이전 경유 노드
	int *distance = new int[MaxNode];	// 시작노드에서 현재노드까지의 비용(거리)
	int *hDistCurToTarget = new int[MaxNode]; // 현재노드에서 타겟노드까지의 추정 비용(거리)
	int *visit = new int[MaxNode];		// 현재 노드의 방문 여부 : UNVISIT or VISITED

	int **gameMap = map.getMap();
	//변수의 초기화
	for (int i = 0; i < MaxNode; i++) {
		visit[i] = UNVISIT;
		distance[i] = 1000;
		hDistCurToTarget[i] = 1000;
		parent[i] = -1;
	}
	//시작노드 방문
	parent[sNode] = sNode;
	distance[sNode] = 0;
	for (int node = 0; node < MaxNode; node++) {
		int curNode = choose(distance, hDistCurToTarget, MaxNode, visit);
		visit[curNode] = VISITED;

		cout << "Choose Node : " << curNode << endl;
		if (curNode == tNode) {
			bFound = true;
			break;
		}
		//엣지 완화 알고리즘
		for (int nextNode = 0; nextNode < MaxNode; nextNode++) {
			//경유해서 가는 비용이 더 작다면
			if (!visit[nextNode] && (distance[curNode] + gameMap[curNode][nextNode] < distance[nextNode])) {
				distance[nextNode] = distance[curNode] + gameMap[curNode][nextNode];
				hDistCurToTarget[nextNode] = gameMap[nextNode][tNode];
				parent[nextNode] = curNode;
			}
			cout << distance[nextNode] << endl;
		}
	}
	//거꾸로 스택에 넣음. target Node가 가장 처음 들어감.
	if (bFound) {
		int node;
		node = tNode;
		pushNode(node);
		do {
			node = parent[node];
			pushNode(node);
		} while (node != sNode);
	}
	return bFound;
}
