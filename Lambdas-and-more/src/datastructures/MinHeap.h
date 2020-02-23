#pragma once
#include <vector>

class MinHeap
{
public:
	void insert(int value) const;
	void remove(int value) const;
	int getSize() const;
	int peekMax();
	int popMax();
	
private:
	std::vector<int> mHeap;
	int mSize = 0;
};
