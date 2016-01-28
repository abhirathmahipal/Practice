// Implementation of Merge Sort

#include <stdio.h>
void merge(int, int, int);
void partition(int, int);

int array[50];

int main (void)
{
	int count;
	printf("Enter the Number of Elements (max 50)\n");
	scanf("%d", &count);

	printf("Enter the Elements\n");
	for (int i = 0; i < count; i++)
	{
		printf("Element Number %d\n", i + 1);
		scanf("%d", &array[i]);
	}

	printf("Unsorted Array\n");
	for (int i = 0; i < count; i++)
		printf("%d ",array[i]);

	partition(0, count - 1);

	printf("\nSorted Array\n");
	for (int i = 0; i < count; i++)
		printf("%d ",array[i]);

	return 0;
}

// Function Definitions

void partition(int start, int end)
{
	if (start < end)
	{
		int m = (start + end)/2;
		partition(start, m);
		partition(m + 1, end);
		merge(start, m , end);
	}

}

void merge(int start, int m, int end)
{

	int lengthLeft = m - start + 1;
	int lengthRight = end - m;

	int leftArray[lengthLeft], rightArray[lengthRight];

	// Copying elements from original array
	for (int i = 0; i < lengthLeft; i++)
		leftArray[i] = array[start + i];

	for (int i = 0; i < lengthRight; i++)
		rightArray[i] = array[m + 1 + i];

	int leftIterate = 0, rightIterate = 0, originalIterate = start;

	while(leftIterate < lengthLeft && rightIterate < lengthRight)
	{
		if (leftArray[leftIterate] < rightArray[rightIterate])
		{
			array[originalIterate] = leftArray[leftIterate];
			leftIterate++;
			originalIterate++;
		}
		else
		{
			array[originalIterate] = rightArray[rightIterate];
			rightIterate++;
			originalIterate++;
		}
	}

	while (leftIterate < lengthLeft)
	{
		array[originalIterate] = leftArray[leftIterate];
		leftIterate++;
		originalIterate++;
	}

	while (rightIterate < lengthRight)
	{
		array[originalIterate] = rightArray[rightIterate];
		rightIterate++;
		originalIterate++;
	}

}
