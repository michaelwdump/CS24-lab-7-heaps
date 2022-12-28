// heap.cpp
// Student name: Daryon Roshanzaer 5701388
// Studnet name: Michael Wong 6209282
//

#include "heap.h"
#include <iostream>
#include <cmath>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
	int valueIndex = 0;
	if (!vdata.empty()) {
		valueIndex = vdata.size();
	}
	vdata.push_back(value);
	if (vdata.size() != 1) {
		int parentIndex = ( (valueIndex - 1) / 2 );
		while (vdata.at(parentIndex) > vdata.at(valueIndex) && valueIndex != 0) {
			int tempValue = vdata.at(parentIndex);
			vdata.at(parentIndex) = vdata.at(valueIndex);
			vdata.at(valueIndex) = tempValue;
			valueIndex = parentIndex;
			parentIndex = floor((valueIndex - 1) / 2 );
		}
	}
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
	if (!vdata.empty()) {
		int currIndex = 0;
		int leftChild = 2 * currIndex + 1;
		int rightChild = 2 * currIndex + 2;
		int lastIndex = vdata.size() - 1;
		vdata.at(0) = vdata.at(lastIndex);
		vdata.pop_back();
		while ( (vdata.size() > rightChild) && (vdata.at(currIndex) >= vdata.at(leftChild) || vdata.at(currIndex) >= vdata.at(rightChild)) ) {
			if (leftChild == vdata.size() - 1) {
				int tempValue = vdata.at(leftChild);
				vdata.at(leftChild) = vdata.at(currIndex);
				vdata.at(currIndex) = tempValue;
				currIndex = leftChild;
			}
			else if (vdata.at(leftChild) < vdata.at(rightChild) ) {
				int tempValue = vdata.at(leftChild);
				vdata.at(leftChild) = vdata.at(currIndex);
				vdata.at(currIndex) = tempValue;
				currIndex = leftChild;
			}
			else {
				int tempValue = vdata.at(rightChild);
				vdata.at(rightChild) = vdata.at(currIndex);
				vdata.at(currIndex) = tempValue;
				currIndex = rightChild;
			}
			leftChild = 2 * currIndex + 1;
			rightChild = 2 * currIndex + 2;
		}
		
		if (vdata.size() == 2) {
			if (vdata.at(currIndex) > (vdata.at(leftChild))) {
			int tempValue = vdata.at(leftChild);
			vdata.at(leftChild) = vdata.at(currIndex);
			vdata.at(currIndex) = tempValue;
			}
		}
	}
}

// Returns the minimum element in the heap
int Heap::top(){
	return vdata.at(0);
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
	if (vdata.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}
    
