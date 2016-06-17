//https://www.hackerrank.com/challenges/the-quickest-way-up


#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int returnmin(int, int);

int main ()
{
	int specialvertices[40], specialindex, doesbelong, adjmatrix[101][101], visited[101], distance[101];

	int snacount, ladcount, test;

	int holdinglist[101];
	int w, min, index, v;


	cin>>test;

	for (int z = 0; z < test; z++)
	{
		// Making everything inaccessible in adjmatrix

		for (int i = 1; i < 101; i++)
		{
			distance[i] = INT_MAX;
			visited[i] = 0;

			for (int j = 1; j < 101; j++)
			{
				adjmatrix[i][j] = -1;
			}
		
		}

		// Special Vertices stores vertices which are foots of ladders or the mouths of snakes
		for (int i = 0; i < 40; i++)
			specialvertices[i] = 0;

			specialindex = -1;



		cin>>ladcount;
		for (int i = 0, from, to; i < ladcount; i++)
		{
			cin>>from;
			cin>>to;
			specialvertices[++specialindex] = from;
			adjmatrix[from][to] = 0;

		}

		cin>>snacount;
		for (int i = 0, from, to; i < snacount; i++)
		{
			cin>>from;
			cin>>to;
			specialvertices[++specialindex] = from;
			adjmatrix[from][to] = 0;
		}
		
		// Filling generic edges. They cost one die roll
		for (int i = 1; i < 101; i++)
		{
			doesbelong = 0;

			for (int a = 0; a < 40; a++)
			{
				if (i == specialvertices[a])
				{
					doesbelong = 1;
					break;
				}
			}

			if (doesbelong == 0)
			{
				for (int j = 1, temp = i + j; j < 7 && temp < 101; j++, temp++)
				{	
					// Each die roll costs 1, so reachable places are marked 1
					adjmatrix[i][temp] = 1;

				}		

			}
		
		}

		// Graph Algorithm here
		// Implementing Dijkstra's here. Finding the least cost
		// from 1 to all other places.

		adjmatrix[1][1] = 0;		
		holdinglist[0] = 1;
		w = 0;
		min = 9999;
		distance[1] = 0;

		while (1)
		{
			
			v = holdinglist[w];
			visited[v] = 1;

			// Recording distances from v via different paths
			// Finding the least weighted node and adding it to holdinglist

			for (int i = 1; i < 101; i++)
			{
				if (adjmatrix[v][i] != -1)
				{
					distance[i] = returnmin(distance[i], distance[v] + adjmatrix[v][i]);

				}
			
			}
			
			for (int i = 1; i < 101; i++)
			{
				if (distance[i] < min && visited[i] == 0)
					min = distance[i], index = i;
			
			}


			min = INT_MAX;

			// If it returns the same element as before. If we eliminate this step, we can use a for loop and set it to run
			// V - 1 times.

			if (index == holdinglist[w])
				break;
			else
				holdinglist[++w] = index;			

		}

		if (distance[100] == INT_MAX)
			distance[100] = -1;
	
		cout << distance[100] << endl;

	}



	return 0;
}


int returnmin (int x, int y)
{

	if (x > y)
		return y;
	else
		return x;
}





/*
// This solution uses linked lists but it doesn't work. Yet to correct it.

int main () 
{
	typedef struct node
	{
		int n;
		struct node *next;
	} node;
	int test, ladcount, snacount, size = sizeof(node), count[101];
	cin>>test;

	node adjlist[101];
	queue <int> queuelist;
	int queuetemp, there, play = 1;


	for (int z = 0; z < test; z++)
	{
		there = 0;
		for (int i = 1; i < 101; i++)
		{
			adjlist[i].next = NULL;
			adjlist[i].n = i;
			count[i] = -1;
		}

		// Handling ladders and filling directed graphs
		cin>>ladcount;
		for (int i = 0, from, to; i < ladcount; i++)
		{
			cin>>from;
			cin>>to;
			adjlist[from].next = (node*) malloc(size);
			adjlist[from].next -> n = to;

		}

		// Handling snakes and filling directed graphs

		cin>>snacount;

		for (int i = 0, from, to; i < snacount; i++)
		{
			cin>>from;
			cin>>to;
			adjlist[from].next = (node*) malloc(size);
			adjlist[from].next -> n = to;
		}

		// Filling edges (for normal dice roll)
		// only if it is empty (ladders and snakes can only direct to one position)
		node *link, *freelink;

		for (int i = 1; i < 101; i++)
		{
			if (adjlist[i].next == NULL)
			{
				for (int j = 6, temp = i + j; j > 0; j--, temp--)
				{
					if (temp < 101)
					{
						link = adjlist[i].next;
						adjlist[i].next = (node*) malloc(size);
						adjlist[i].next -> n = temp;
						adjlist[i].next -> next = NULL;
						if (link != NULL)
							adjlist[i].next -> next = link;

					}


				}
			}
		}

		// End of adjacency list fill related tasks

		// Test to check array

		for (int i = 1; i < 101; i++)
		{
			cout<< adjlist[i].n << "->";
			link = adjlist[i].next;
			while(link != NULL)
			{
				cout<< link -> n << "->";
				link = link -> next;
			}
			cout << endl;
		} 
		
		// Check if there is a path to 100 or not
		for (int i = 100, holder; i > 0; i++)
		{
			link = adjlist[i].next;
			while(link != NULL)
			{
				holder = link -> n;
				if(holder = 100)
				{
					there = 1;
					break;
				}

				link = link -> next;

			}
			
		}
		// Implement Graph Traversal here
		if (there)	
		{	
			play = 1;
			queuelist.push(1);
			count[1] = 0;
			while(count[100] == -1)
			{
				queuetemp = queuelist.size();
				for (int i = queuelist.front(); queuetemp > 0; i = queuelist.front(), queuetemp--)
				{

					if (count[adjlist[i].n] == -1)
						count[adjlist[i].n] == play;

					link = adjlist[i].next;
					while(link != NULL)
					{
						if (count[link -> n] == -1)
						{
							queuelist.push(link -> n);
							count[link -> n] = play;
						}
						link = link -> next;
					}
					queuelist.pop();
				}
				play++;

			}

			// Empty Queue
			while (queuelist.size() > 0)
				queuelist.pop();


		}
			
		cout<<count[100]<<endl;

		// Freeing memory
		for (int i = 1; i < 101; i++)
		{
			link = adjlist[i].next;
			while (link != NULL)
			{
				freelink = link -> next;
				free(link);
				link = freelink;
			}


		}

		

	// Number of test cases loop
	}

	return 0;
}
*/
