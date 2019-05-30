#include <stdio.h>

int maxSum(int* array, int count)
{
	int sum = 0;
	int b = 0;
	for (int i=0; i<count; ++i)
	{
		if (b<0)
			b = array[i];
		else
			b += array[i];
		if (sum < b)
			sum = b;
	}
	return sum;
}

int main()
{
	int array[10] = {1, -2, 3, 4, -5, 6, -7, 8, 9, 10}; 
	int max = maxSum(array, sizeof(array)/sizeof(int));
	printf("max sum of array is : %d\n", max);
	return 0;
}
