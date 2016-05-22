#include "Dijkstra.h"
#include "Astar.h"
#include "MyMap.h"
#include "MyPath.h"
#include "mapInfo.h"
#include <iostream>
using namespace std;

void main() 
{
	int *map[MAXNODE];
	for (int i = 0; i < MAXNODE; i++) {
		map[i] = new int[MAXNODE];
	}
	for (int i = 0; i < MAXNODE; i++) {
		for (int j = 0; j < MAXNODE; j++)
			map[i][j] = cost[i][j];
	}

	CMyMap gameMap(MAXNODE, MAXNODE);
	gameMap.setMap(map);
	gameMap.draw();

	CMyPath *shortPath;
	CDijkstra dijkstra;

	shortPath = &dijkstra;
	shortPath->findPath(3, 0, gameMap);
	cout << "Dijkstra Path : ";
	shortPath->draw();
	cout << endl;

	CAstar astar;
	shortPath = &astar;
	shortPath->findPath(3, 0, gameMap);
	cout << "Astar Path : ";
	shortPath->draw();
	cout << endl;

	
}