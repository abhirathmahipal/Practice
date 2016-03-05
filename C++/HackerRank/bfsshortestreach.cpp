// https://www.hackerrank.com/challenges/bfsshortreach

#include <iostream>

using namespace std;

int main ()
{

	int test, node, edgecount, start, queue[1001];
	int graph[1001][1001], temp, rear, front;
	int distance[1001];
	bool processed[1001];
	cin >> test;

	for (int z = 0; z < test; z++)
	{
		cin >> node >> edgecount;


		// Making all nodes in accessible
		for (int i = 1; i <= node; i++)
		{
			for (int j = 1; j <= node; j++)
				graph[i][j] = -1;

			distance[i] = -1, processed[i] = false;
		}

		// Getting input of the edges.
		for (int i = 0, temp1 = 0, temp2 = 0; i < edgecount; i++)
		{
			cin >> temp1 >> temp2;
			graph[temp1][temp2] = 6;
			graph[temp2][temp1] = 6;
		}

		cin >> start;

		// Performing a bfs
		rear = -1, front = -1;
		queue[++rear] = start;
		distance[start] = 0;

		while (rear != front)
		{
			temp = queue[++front];
			processed[temp] = true;
			for (int i = 1; i <= node; i++)
			{
				if (graph[temp][i] == 6 && distance[i] == -1)
				{
					distance[i] = distance[temp] + graph[temp][i];
						
						if (processed[i] == false)
							queue[++rear] = i;
				}
				
			}
		}


		
		// Printing output
		for (int i = 1; i <= node; i++)
			if (i != start)
				cout << distance[i] << " ";

		cout << endl;
	}

	return 0;
}