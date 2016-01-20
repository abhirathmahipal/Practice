// Implements insertion sort

#include <stdio.h>

int main (void)
{
	int arr[30], count;
	printf("Enter the number of elements (max 30)\n");
	scanf("%d", &count);

	for (int i = 0, j = 1; i < count; i++, j++)
	{
		printf("Element No. %d\n", j);
		scanf("%d", &arr[i]);
	}

	// Insertion Sort
	int temp = 0;

	for (int i = 0; i < count; i++)
	{

		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}

	}

	// Printing Elements
	for (int i = 0; i < count; i++)
		printf("%d ",arr[i]);

	return 0;

}