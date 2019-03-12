#pragma once

#include <stack>

using namespace std;


class QueueTwoStacks
{
private:
	stack<int> inStack;
	stack<int> outStack;

public:
	void Enqueue(int item);
	int Dequeue();
	bool Empty();

};