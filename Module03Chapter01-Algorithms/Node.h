#pragma once
#include "Edge.h"
#include <list>

class Node {
public:
	char ID;
	int dist;
	int heuristic;
	std::list<Edge*> pathOut;
	Node* lastNode;

	Node(char newID) {
		ID = newID;
		dist = -1;
		heuristic = 0;
		lastNode = nullptr;
	}
};