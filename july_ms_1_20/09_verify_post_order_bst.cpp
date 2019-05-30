#include <stdio.h>

bool verify(int* array, int length)
{
	if (array == NULL || length <= 0)
		return false;

	// locate the root of the bst
	int root = array[length-1];

	// left child of the root shall be less than root;
	int i = 0;
	for (; i<length-1; ++i)
	{
		if (array[i] > root)
			break;
	}

	for (int j=i; j<length-1; ++j)
	{
		if (array[j] <= root)
			return false;
	}
	
	// verify the left child
	bool left = true;
	if (i > 0)
		left = verify(array, i);
	
	// verify the right child
	bool right = true;
	if (i < length-1)
		right = verify(array+i, length-i-1);

	return left&&right;
}

int main()
{
	int array[] = {5, 7, 6, 9, 11, 10, 8};
	bool success = verify(array, sizeof(array)/sizeof(int));
	printf("%d\n", success);
	return 0;
}


