#include <stdio.h>

void swap(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}

void bubbleSort(int *array, int len)
{
	for (int i=len; i>0; i--)
		for (int j=0; j<i; j++)
			if (array[j] > array[j+1])
				swap(array[j], array[j+1]);
}

void printArray(int *array, int len)
{
	for (int i=0; i<len; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	int array[] = {5, 3, 2, 4, 1};
	int len = sizeof(array)/sizeof(int);
	bubbleSort(array, len);
	printArray(array, len);
}
