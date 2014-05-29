#include <stdio.h>
#include <unistd.h>
#include <string.h>

void merge(int *array, int m, int len)
{
	int *temp = new int[len];
	memset(temp, 0, len*sizeof(int));
	
	int i=0, j=m, k=0;
	for (; i<m && j<len; ++k)
	{
		if (array[i] < array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
	}
	
	while (i<m)
		temp[k++] = array[i++];
	while (j<len)
		temp[k++] = array[j++];
	
	memcpy(array, temp, len*sizeof(int));
	delete []temp;
}

void mergeSort(int *array, int len)
{
	if (len <= 1)
		return;
	int m = len/2;
	mergeSort(array, m);
	mergeSort(array+m , len-m);
	merge(array, m, len);
}

int main()
{
	int array[] = {5, 3, 2, 4, 1};
	int len = sizeof(array)/sizeof(int);
	mergeSort(array, len);
	for (int i=0; i<len; ++i)
		printf("%d ", array[i]);
	printf("\n");
}
