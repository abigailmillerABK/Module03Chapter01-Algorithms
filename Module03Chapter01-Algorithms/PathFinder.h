#pragma once
#include <list>
#include "Node.h"
#include <cassert>

class PathFinder {
	std::list<Node*> knownNodes;
	std::list<Node*> unknownNodes;
	std::list<Node*> allNodes;

public:
	void addPath(char start, char end, int cost);
	Node* GetNodeByChar(char nodeChar);
	int findPath(char start, char end);
	void MakeKnown(Node* thisNode);
	void clearData();
};