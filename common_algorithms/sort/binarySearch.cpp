#include <stdio.h>

int binarySearch(int* array, int length, int value)
{
	int l = 0, r = length-1, middle;
	do
	{
		middle = (l+r)/2;
		if (value > array[middle])
			l = middle + 1;
		else if (value < array[middle])
			r = middle - 1;
		else
			return middle;
	} while (l < r);
	return -1;
}

int main()
{
	int array[] = { 2 };
	int result = binarySearch(array, sizeof(array)/sizeof(int), 1);
	printf("result : %d\n", result);
	return 0;
}
