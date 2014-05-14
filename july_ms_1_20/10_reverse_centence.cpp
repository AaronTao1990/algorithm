#include <stdio.h>
#include <string.h>

void reverse(char* array, int length)
{
	for (int i=0, j=length-1; i<j; ++i, --j)
	{
		char temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

void reverseCentence(char* array, int length)
{
	// reverse the how centence first
	reverse(array, length);
	
	// reverse each word
	int i=0, j=0;
	for (; j<length; ++j)
	{
		if (array[j] == ' ')
		{
			reverse(array+i, j-i);
			i = j+1;
		}
	}
	reverse(array+i, j-i);
}

int main()
{
	char centence[] = "this is a centence";
	reverseCentence(centence, strlen(centence));
	printf("%s\n", centence);
}
