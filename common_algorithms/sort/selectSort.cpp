#include <stdio.h>

void swap(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}

void selectSort(int *array, int len)
{
	int max;
	for (int i=0; i<len-1; ++i)
	{
		max = i;
		for (int j=i; j<len; ++j)
		{
			if (array[j] < array[max])
				max = j;
		}
		swap(array[i], array[max]);
	}
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
	selectSort(array, len);
	printArray(array, len);
}
