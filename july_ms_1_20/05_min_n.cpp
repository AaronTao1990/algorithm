#include <stdio.h>

class MaxHeap {
public:
	explicit MaxHeap(int size);
	~MaxHeap();
	
	void sinkDown();
	void sinkUp();
	void push(int value);
	void printArray();

private:
	int maxSize;
	int currentSize;
	int* array;
};


MaxHeap::MaxHeap(int size)
{
	maxSize = size;
	array = new int[maxSize];
	currentSize = 0;
}

MaxHeap::~MaxHeap()
{
	if (array != NULL)
	{
		delete[] array;
		array = NULL;
	}
}

void MaxHeap::push(int value)
{
	if (currentSize < maxSize)
	{
		array[currentSize++] = value;
		sinkUp();
	}
	else if (value >= array[0])
	{
		return;
	}
	else
	{
		array[0] = value;
		sinkDown();
	}
}

void MaxHeap::sinkDown()
{
	int k = 0;
	int value = array[k];
	for (int i=1; i<currentSize; i=2*i+1)
	{
		if ((i+1 < currentSize) &&
			(array[i] < array[i+1]))
			i++;
		if (array[i] > array[k])
		{
			array[k] = array[i];
			k = i;
		}
		else
		{
			break;
		}
	}
	array[k] = value;
}

void MaxHeap::sinkUp()
{
	int k = currentSize-1;
	int value = array[k];
	for (int i=(k-1)/2; i>=0; i=(i-1)/2)
	{
		if (array[i] < array[k])
		{
			array[k] = array[i];
			k = i;
		}
		else
		{
			break;
		}
	}
	array[k] = value;
}

void MaxHeap::printArray()
{
	for (int i=0; i<currentSize; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	MaxHeap heap(4);
	heap.push(2);
	heap.push(4);
	heap.push(7);
	heap.push(3);
	heap.push(5);
	heap.push(6);
	heap.push(1);
	
	heap.printArray();
	return 0;
}
