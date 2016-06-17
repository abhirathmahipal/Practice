// https://www.hackerrank.com/challenges/primsmstsub

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int main()
{

	// using adjacency list for this problem.
	typedef struct list
	{
		int node;
		int weight;
		list *next;

	} list;

	int n, m, source, distance = 0;
	cin >> n >> m;


	list adjlist[n+1], *iteration;
	int temp, temp2, temp3;
	int key[n+1];
	bool mstset[n+1];

	for (int i = 1; i <= n; i++)
		adjlist[i].next = NULL, key[i] = INT_MAX, mstset[i] = false;

	// Getting input and storing it in a linked list
	for (int i = 0; i < m; i++)
	{
		cin >> temp >> temp2 >> temp3;

		if (adjlist[temp].next == NULL)
		{
			adjlist[temp].next = (list*) malloc(sizeof(list));
			adjlist[temp].next -> node = temp2;
			adjlist[temp].next -> weight = temp3;
			adjlist[temp].next -> next = NULL;
		}
		else
		{
			iteration = adjlist[temp].next;
			adjlist[temp].next = (list*) malloc(sizeof(list));
			adjlist[temp].next -> weight = temp3;
			adjlist[temp].next -> node = temp2;
			adjlist[temp].next -> next = iteration;


		}

		if (adjlist[temp2].next == NULL)
		{
			adjlist[temp2].next = (list*)malloc(sizeof(list));
			adjlist[temp2].next -> node = temp;
			adjlist[temp2].next -> weight = temp3;
			adjlist[temp2].next -> next = NULL;

		}
		else
		{
			iteration = adjlist[temp2].next;
			adjlist[temp2].next = (list*) malloc(sizeof(list));
			adjlist[temp2].next -> node = temp;
			adjlist[temp2].next -> weight = temp3;
			adjlist[temp2].next -> next = iteration;
		}

	}

	
	// For source vertex
	cin >> source;
	key[source] = 0;

	// Main Prim Algorithm. It has to be performed n times to include n vertices
	for (int i = 0; i < n; i++)
	{	

		temp = INT_MAX;
		// Finding min in key array that is unvisited and using that to update
		for (int j = 1; j <= n; j++)
		{
			if (key[j] < temp && mstset[j] == false)
				temp2 = j, temp = key[j];

		}


		mstset[temp2] = true;

		// updating key array with new weights

		iteration = adjlist[temp2].next;
		while (iteration != NULL)
		{

			temp2 = iteration -> node;

			if (mstset[temp2] == false)
			{
				temp3 = iteration -> weight;

				if (temp3 < key[temp2])
					key[temp2] = temp3;
			}

			iteration = iteration -> next;

		}

	}

	for (int i = 1; i <= n; i++)
		distance += key[i];
		
	cout << distance;


	


	return 0;
}