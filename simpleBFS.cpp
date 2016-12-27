#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class graph
{
private:
	int** pArr;
	int pV;
public:
	graph(int n);
	~graph();
	void inputMatrix();
	void bfs();
};


int main()
{
	int n;
	cout<<"Enter the number of vertices in the graph\n";
	cin>>n;
	graph G(n);
	G.inputMatrix();
	G.bfs();
	return 0;
}

graph::graph(int n)
{
	pArr = new int*[n];
	for (int i = 0; i < n; i++)
		pArr[i] = new int[n];
	pV = n;
}

graph::~graph()
{
	for (int i = 0; i < pV; i++)
		delete[] pArr[i];
	delete[] pArr;
}

void graph::inputMatrix()
{
	cout<<"Enter the elements of the adjacency matrix\n";
	for (int i = 0; i < pV; i++)
		for (int j = 0; j < pV; j++)
			cin>>pArr[i][j];
}

void graph::bfs()
{
	bool visited[pV];
	for (int i = 0; i < pV; i++)
		visited[i] = false;
	queue<int> Q;
	visited[0] = true;
	int i = 0;
	Q.push(i);
	while(Q.size() != 0)
	{
		int k = Q.front();
		for (int j = 0; j < pV; j++)
		{
			if ((pArr[k][j] == 1) && !visited[j])
			{
				visited[j] = true;
				Q.push(j);
			}
		} 
		Q.pop();
	}

	int count = 0;
	for (int i = 0; i < pV; i++)
	{
		if (visited[i] == true)
		{
			cout<<i+1<<" ";
			count++;
		}
	}
	if (count == pV)
	{
		cout<<"Connected graph\n";
	}
	else
		cout<<"Not a connected graph\n";

}
