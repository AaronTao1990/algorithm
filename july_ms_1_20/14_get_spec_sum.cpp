#include <stdio.h>

bool getSum(int *array, int len, int sum)
{
	int l = 0;
	int r = len - 1;
	while (l < r)
	{
		int cursum = array[l] + array[r];
		if (cursum == sum)
			return true;
		else if (cursum > sum)
			r--;
		else
			l++;
	}
	return false;
}

int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	bool found = getSum(array, sizeof(array)/sizeof(int), 6);
	printf("%d\n", found);
	return 0;
}
