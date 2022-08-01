#pragma once
#include "Node.h"
#include <list>
#include <iostream>
#include <list>
#include "Path.h"

class SearchTree {
public:
	std::list<Path*> pathList;
	std::list<Node*> nodeList;
	void NewPath(char head, char tail, int cost) {
		//See if nodes already exist
		std::list<Node*>::iterator nodePtr;
		bool createHead = true;
		bool createTail = true;
		Node* headNode = nullptr;
		Node* tailNode = nullptr;
		for (nodePtr = nodeList.begin(); nodePtr != nodeList.end(); nodePtr++) {
			if ((*nodePtr)->myID == head) {
				createHead = false;
				headNode = (*nodePtr);
			}
			if ((*nodePtr)->myID == tail) {
				createTail = false;
				tailNode = (*nodePtr);
			}
		}
		if (createHead) {
			headNode = new Node(head);
			nodeList.push_back(headNode);
		}
		if (createTail) {
			tailNode = new Node(tail);
			nodeList.push_back(tailNode);
		}
		Path* path = new Path(headNode, tailNode, cost);
		pathList.push_back(path);
	}
	int GetShortestPath(char Start, char End, int pathThusFar = 0) {
		//Get paths off of node
		//Get list of paths with node as connector
		std::list<Path*>::iterator pathPtr;
		for (pathPtr = pathList.begin(); pathPtr != pathList.end(); pathPtr++) {
			//If the path is connected
			if (Start == End) {
				return pathThusFar;
			}
			else if ((*pathPtr)->head->myID == Start) {
				int cost = pathThusFar + (*pathPtr)->cost;
				GetShortestPath((*pathPtr)->tail->myID, End, cost);
				//return;
			} 
			else if((*pathPtr)->tail->myID == End) {
				int cost = pathThusFar + (*pathPtr)->cost;
				GetShortestPath((*pathPtr)->head->myID, End, cost);
				//return;
			}
		}
	}
	SearchTree() {
	}
	/*~SearchTree() {
		std::list<Path*>::iterator pathPtr;
		for (pathPtr = pathList.begin(); pathPtr != pathList.end(); pathPtr++) {
			delete &(*pathPtr);
			(*pathPtr) = nullptr;
		}
		std::list<Node*>::iterator nodePtr;
		for (nodePtr = nodeList.begin(); nodePtr != nodeList.end(); nodePtr++) {
			delete& (*nodePtr);
			(*nodePtr) = nullptr;
		}
	}*/
};