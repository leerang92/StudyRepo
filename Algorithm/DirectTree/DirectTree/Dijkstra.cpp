#include "Dijkstra.h"



CDijkstra::CDijkstra()
{
}

CDijkstra::~CDijkstra()
{
}

enum {UNVISIT, VISITED };
#include <iostream>
using namespace std;

int CDijkstra::choose(int distance[], int maxNode, int visit[])
{
	int curNode;
	int minCost, minNode;

	minCost = 9999;
	minNode = -1;
	//����� ���� ���� ��� ã�� ������.
	for (curNode = 0; curNode < maxNode; curNode++) {
		if (!visit[curNode] && distance[curNode] < minCost) {
			minCost = distance[curNode];
			minNode = curNode;
		}
	}
	return minNode;
}

//sNode : start,	tNode : targetNode
bool CDijkstra::findPath(int sNode, int tNode, CMyMap map)
{
	bool bFound = false;
	int MaxNode = map.getWidth();		// ����� �� ����
	int *parent = new int[MaxNode];		// ���� ����� ���� ���� ���
	int *distance = new int[MaxNode];	// ���۳�忡�� ����������� ���(�Ÿ�)
	int *visit = new int[MaxNode];		// ���� ����� �湮 ���� : UNVISIT or VISITED

	int **gameMap = map.getMap();
	//������ �ʱ�ȭ
	for (int i = 0; i < MaxNode; i++) {
		visit[i] = UNVISIT;
		distance[i] = 1000;
		parent[i] = -1;
	}
	//���۳�� �湮
	parent[sNode] = sNode;
	distance[sNode] = 0;
	for (int node = 0; node < MaxNode; node++) {
		int curNode = choose(distance, MaxNode, visit);
		visit[curNode] = VISITED;
		
		cout << "Choose Node : " << curNode << endl;
		if (curNode == tNode) {
			bFound = true;
			break;
		}
		//���� ��ȭ �˰���
		for (int nextNode = 0; nextNode < MaxNode; nextNode++) {
			//�����ؼ� ���� ����� �� �۴ٸ�
			if (!visit[nextNode] && (distance[curNode] + gameMap[curNode][nextNode] < distance[nextNode])) {
				distance[nextNode] = distance[curNode] + gameMap[curNode][nextNode];
				parent[nextNode] = curNode;
			}
			cout << distance[nextNode] << endl;
		}
	}
	//�Ųٷ� ���ÿ� ����. target Node�� ���� ó�� ��.
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
