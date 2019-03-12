#include <stack>
#include <iostream>
#include "queue.h"

using namespace std;

void ShowStack(const stack<int>& stackParam)
{
	stack<int> g= stackParam;

	while (!g.empty())
	{
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

void ShowQueue(const QueueTwoStacks& queueParam)
{
	QueueTwoStacks q = queueParam; // won't cause memory leak

	while (!q.Empty())
	{
		cout << '\t' << q.Dequeue();
	}
	cout << '\n';
}

int main()
{
	
	QueueTwoStacks myQueue;

	myQueue.Enqueue(1);
	myQueue.Enqueue(2);
	myQueue.Enqueue(3);

	ShowQueue(myQueue);

	myQueue.Dequeue();
	myQueue.Enqueue(4);

	ShowQueue(myQueue);
	
}