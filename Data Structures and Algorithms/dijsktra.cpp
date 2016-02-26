// http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
#include <iostream>
#include <limits.h>

#define V 9

using namespace std;

int minDistance(int dist[], bool sptSet[]);
int printSolution(int dist[]);
void dijkstra(int graph[V][V], int src);


int main ()
{
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}};
 
    dijkstra(graph, 0);
 
	return 0;
}

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX;
	int min_index;

	for (int i = 0; i < V; i++)
		if (sptSet[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;

	return min_index;
}

int printSolution(int dist[])
{
	cout << "Distance of all vertices from source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << ".\t" << dist[i] << endl;

}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	// We need to iterate 8 times (8 other remaining edges other than the source) i.e number of vertices - 1
	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)
		{
			// graph[u][v] in if means if it isn't zero
			if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}

		
	}

	printSolution(dist);

}
