#include <stdio.h>

int sort(int *array, int len)
{
	int l = 0;
	int r = len - 1;
	int value = array[l];
	while (l < r)
	{
		while (l<r && array[r]>value)
		{
			r--;
		}
	
		if (l == r)
			break;

		if (l < r)
		{
			array[l] = array[r];
			l++;
		}
		
		while (l<r && array[l]<value)
		{
			l++;
		}
		if (l == r)
			break;
		if (l < r)
		{
			array[r] = array[l];
			r--;
		}
	}
	
	array[l] = value;
	return l;
}

void quickSort(int *array, int len)
{
	if (len <= 1)
		return;

	int middle = sort(array, len);
	quickSort(array, middle);
	quickSort(array+middle+1, len-middle-1);
}

int main()
{
	int array[] = {3, 2, 5, 4, 1, 10, 11};
	int len = sizeof(array)/sizeof(int);
	quickSort(array, len);
	for (int i=0; i<len; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

