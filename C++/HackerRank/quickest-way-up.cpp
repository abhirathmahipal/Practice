//https://www.hackerrank.com/challenges/the-quickest-way-up

// This solution doesn't work. Yet to correct it.

#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;


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

