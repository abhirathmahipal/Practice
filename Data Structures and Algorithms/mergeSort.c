// Implementation of Merge Sort

#include <stdio.h>

int mergesort(int*, int , int);
int main (void)
{
	int array[40];

	for (int i = 0; i < 40; i++)
	{
		scanf("%d", &array[i]);
	}

	int result = mergesort(&array, 0, 39);

	if (result == 0)
	{
		for (int i = 0; i < 40; i++)
			printf("%d ", &array[i]);		
	}

	return 0;

}

int mergesort(int *arr, int start, int end)
{
	

}


