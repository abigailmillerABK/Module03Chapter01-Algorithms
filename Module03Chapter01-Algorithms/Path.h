#pragma once
#include "Node.h"

class Path {
public:
	Node* head;
	Node* tail;
	int cost;

	Path(Node* newHead, Node* newTail, int newCost) {
		head = newHead;
		tail = newTail;
		cost = newCost;
	}
};