#pragma once
#include <list>
#include "Node.h"
#include <cassert>

class PathFinder {
	std::list<Node*> knownNodes;
	std::list<Node*> unknownNodes;
	std::list<Node*> allNodes;

public:
	void addPath(char start, char end, int cost) {
		//Make sure that the data is clean
		clearData();
		//See if nodes exist already
		bool startCreated = false;
		Node* startNode = nullptr;
		bool endCreated = false;
		Node* endNode = nullptr;
		std::list<Node*>::iterator charPtr;
		for (charPtr = unknownNodes.begin(); charPtr != unknownNodes.end(); charPtr++) {
			if (start == (*charPtr)->ID) {
				startCreated = true;
				startNode = (*charPtr);
			}
			else if (end == (*charPtr)->ID) {
				endCreated = true;
				endNode = (*charPtr);
			}
		}
		//Create nodes
		if (!startCreated) {
			startNode = new Node(start);
			unknownNodes.push_back(startNode);
			allNodes.push_back(startNode);
		}
		if (!endCreated) {
			endNode = new Node(end);
			unknownNodes.push_back(endNode);
			allNodes.push_back(endNode);
		}
		//Create path
		Edge* newEdge = new Edge(end, cost);
		startNode->pathOut.push_back(newEdge);
	}
	Node* GetNodeByChar(char nodeChar) {
		std::list<Node*>::iterator charPtr;
		for (charPtr = allNodes.begin(); charPtr != allNodes.end(); charPtr++) {
			if ((*charPtr)->ID == nodeChar) {
				return (*charPtr);
			}
		}
	}
	int findPath(char start, char end) {
		clearData();
		//set start dist = to 0
		Node* startNode = GetNodeByChar(start);
		startNode->dist = 0;
		//MakeKnown(startNode);
		while (!unknownNodes.empty()) {
			//get node with shortest distance
			int dist = 99999; //some large number
			Node* activeNode = nullptr;
			std::list<Node*>::iterator charPtr;
			for (charPtr = unknownNodes.begin(); charPtr != unknownNodes.end(); charPtr++) {
				if ((*charPtr)->dist != -1 && ((*charPtr)->dist+(*charPtr)->heuristic < dist)) {
					dist = (*charPtr)->dist;
					activeNode = *charPtr;
				}
			}
			//For each edge
			std::list<Edge*>::iterator edgePtr;
			assert(activeNode != nullptr);
			for (edgePtr = activeNode->pathOut.begin(); edgePtr != activeNode->pathOut.end(); edgePtr++) {
				//check if distance of next node should decrease
				int newDist = activeNode->dist + (*edgePtr)->cost;
				Node* nextNode = GetNodeByChar((*edgePtr)->to);
				if (nextNode->dist == -1 || nextNode->dist > newDist) {
					nextNode->dist = newDist;
					nextNode->lastNode = activeNode;
				}
			}
			//Move node to known
			MakeKnown(activeNode);
		}
		//Print path that was taken
		Node* nodePtr = GetNodeByChar(end);
		std::cout << "\n" << end;
		do  {
			nodePtr = nodePtr->lastNode;
			if (nodePtr != nullptr) {
				std::cout << "<-" << nodePtr->ID;
			}
		} while (nodePtr != nullptr);
		return GetNodeByChar(end)->dist;
	}
	void MakeKnown(Node* thisNode) {
		std::list<Node*>::iterator charPtr;
		knownNodes.push_back(thisNode);
		unknownNodes.remove(thisNode);
	}

	void clearData() {
		std::list<Node*>::iterator charPtr;
		for (charPtr = knownNodes.begin(); charPtr != knownNodes.end(); charPtr++) {
			knownNodes.back()->dist = -1;
			unknownNodes.push_back(knownNodes.back());
			knownNodes.pop_back();
		}
	}
};