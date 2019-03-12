#include "queue.h"

void QueueTwoStacks::Enqueue(int item)
{
	inStack.push(item);
}

int QueueTwoStacks::Dequeue()
{
	if (outStack.empty())
	{
		while (!inStack.empty())
		{
			outStack.push((inStack.top()));
			inStack.pop();
		}

		if (outStack.empty())
		{
			throw runtime_error("Can't dequeue from empty queue!");
		}
	}
	
	int dequeueResult = outStack.top();
	outStack.pop();
	return dequeueResult;

}

bool QueueTwoStacks::Empty()
{
	return (inStack.empty() && outStack.empty());
}