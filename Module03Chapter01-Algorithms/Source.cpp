/*
Created by Abigail Miller

Challenges:

1. Implement a sorting algorithm using the chrono library profile, sometimes using varying sample sizes

2. Write an A* implementation that reads coordinates labeled (x,y,cost) where x & y are letters that define
a connection, and cost is a number that represents the cost.

Sample map to traverse:

(a,b,5)
(b,c,1)
(a,d,7)
(c,d,1)
Sample path request:

(a,d)
3. The program should determine if it's possible to reach a destination given the starting point.
It should also find the cheapest path, making sure to output the cost of the path
*/

#include <iostream>
#include <chrono>
#include <string>
#include "Node.h"
#include "PathFinder.h"

void printArray(int thisList[], int sizeOf) {
	std::cout << "\nArray values:\n";
	for (int i = 0; i < sizeOf; i++) {
		std::cout << std::to_string(thisList[i]) << " ";
	}
	std::cout << "\n";
}

void bubbleSort(int thisList[], int sizeOf) {	
	std::cout << "\nStart bubble sort\n";
	auto start = std::chrono::steady_clock::now();
	//Number of passes
	for (int j = 0; j < sizeOf; j++) {
		//compare each element
		bool didSwap = false;
		for (int k = 0; k < sizeOf - 1; k++) {
			//compare elements
			if (thisList[k] > thisList[k + 1]) {
				//swap
				didSwap = true;
				int temp = thisList[k];
				thisList[k] = thisList[k + 1];
				thisList[k + 1] = temp;
			}
		}
		if (didSwap == false) {
			//no need to continue passes
			auto end = std::chrono::steady_clock::now();
			auto timeSpent = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			std::cout << "Ended bubble sort at pass " << std::to_string(j) << "\n";
			std::cout << "Time spent: " << std::to_string(timeSpent) << " nanoseconds\n";
			return;
		}
	}
	auto end = std::chrono::steady_clock::now();
	auto timeSpent = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << "Ended complete bubble sort\n";
	std::cout << "Time spent: " << std::to_string(timeSpent) << " nanoseconds\n";
	return;
}

void LinearSearch(int myData[], int sizeOf, int searchKey)
{
	std::cout << "\nStart Linear Search\n";
	for (int i = 0; i < sizeOf; i++) {
		if (myData[i] == searchKey) {
			std::cout << "Found search key " << std::to_string(searchKey) << " at index " << std::to_string(i) << "\n";
			return;
		}
	}
}

void BinarySearch(int myData[], int sizeOf, int searchKey) {
	std::cout << "\nStart Binary Search\n";
	int lowIndex = 0;
	int highIndex = sizeOf - 1;
	while (lowIndex != highIndex) {
		int middleIndex = (highIndex + lowIndex) / 2;
		if (myData[middleIndex] != searchKey) {
			if (myData[middleIndex] > searchKey) {
				highIndex = middleIndex - 1;
			}
			else {
				lowIndex = middleIndex + 1;
			}
		}
		else {
			std::cout << "Found search key " << std::to_string(searchKey) << " at index " << std::to_string(middleIndex) << "\n";
			return;
		}
	}
	std::cout << "Found search key " << std::to_string(searchKey) << " at index " << std::to_string(lowIndex) << "\n";
	return;
}

int main() {
	int myData[] = { 5,0,9,1,3,25,6,6,1,8,5,3 };
	int dataSize = 12;
	printArray(myData, dataSize);
	bubbleSort(myData, dataSize);
	printArray(myData, dataSize);
	LinearSearch(myData, dataSize, 25);
	BinarySearch(myData, dataSize, 25);

	PathFinder myPath;
	myPath.addPath('a','b',5);
	myPath.addPath('b', 'c', 1);
	myPath.addPath('a', 'd', 8);
	myPath.addPath('c', 'd', 1);

	int dist = myPath.findPath('a', 'd');

	std::cout << "\nPath found in #steps: " << dist << "\n";
	return 0;
}
