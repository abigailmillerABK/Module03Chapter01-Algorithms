#pragma once

class Edge {
public:
	int cost;
	char to;

	Edge(char to, int cost) {
		this->to = to;
		this->cost = cost;
	}
};