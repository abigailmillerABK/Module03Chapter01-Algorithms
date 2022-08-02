#pragma once
#include "Edge.h"
#include <list>

struct Node {
	char ID;
	int dist;
	int heuristic;
	std::list<Edge*> pathOut;
	Node* lastNode;

	Node(char newID) {
		ID = newID;
		dist = -1; //uninitialized
		heuristic = 0;
		lastNode = nullptr;
	}
};