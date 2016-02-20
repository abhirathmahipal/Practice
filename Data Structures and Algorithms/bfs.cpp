// http://lectnote.blogspot.in/2012/07/adjacency-matrices-are-several.html
#include <iostream>
#include <stdio.h>


using namespace std;

void showGraph();
void dfs(int);
void bfs(int);


int adjmatrix[5][5] = { {0, 1, 0, 1, 1},
{0, 0, 0, 1, 0},
{0, 0, 0, 0, 1},
{0, 0, 0, 0, 0},
{0, 1, 0, 0, 0}
};

bool visited[5];

int main ()
{
	int x;
	showGraph();


	cout << "Enter Starting Point for BFS" << endl;
	cin >> x;

	for (int i = 0; i < 5; i++)
		visited[i] = false;

	cout << "Solution:-" << endl;

	bfs(x);



	cout << endl <<  "Enter Starting Node for DFS" << endl;
	cin >> x;

	for (int i = 0; i < 5; i++)
		visited[i] = false;


	cout << "Solution:-" << endl;

	dfs(x);



	return 0;
}

void showGraph()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%4d", adjmatrix[i][j]);

		}
		cout << endl;
	}

}

void dfs(int v)
{
	int i;
	visited[v] = true;
	for (int i = 0; i < 5; i++)
	{
		if(adjmatrix[v][i] == 1 && visited[i] == false)
			dfs(i);
	}

	cout << v << " ";

}

void bfs(int v)
{
	int front = 0, rear = 0;
	int que[5];


	cout << v << " ";
	visited[v] = true;
	que[0] = v;

	while (front <= rear)
	{
		v = que[front];
		front++;
		for (int i = 0; i < 5; i++)
		{

			if (adjmatrix[v][i] == 1 && visited[i] == false)
			{
				cout << i << " ";
				visited[i] = true;
				que[++rear] = i;
			}


		}
	}

}