#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class graph
{
	private:
		int **pArr;
		int pV;
	public:
		graph(int v);
		~graph();
		void inputMatrix();
		void dfs();
};

int main()
{
	int v;
	cout<<"Enter the nmber of vertices in the graph\n";
	cin>>v;
	graph G(v);
	cout<<"Enter the adjacency matrix\n";
	G.inputMatrix();
	G.dfs();	
}

graph::graph(int v)
{
	pV = v;
	pArr = new int*[v];
	for (int i = 0; i < v; i++)
	{
		pArr[i] = new int[v];
	}
}

graph::~graph()
{
	for (int i = 0; i < pV; i++)
		delete[] pArr[i];
	delete[] pArr;
}

void graph::inputMatrix()
{
	for (int i = 0; i < pV; i++)
		for (int j = 0; j < pV; j++)
			cin>>pArr[i][j];
}

// non recursive solution
void graph::dfs()
{
	int nVisited = 0;
	bool visited[pV];
	for (int i = 0; i < pV; i++)
		visited[i] = false;
	stack<int> S;
	
	//for (int i = 0; i < pV; i++)
	//{
	//	if (!visited[i])
	//	{
			int i = 0;
			visited[i] = true;
			S.push(i);
			while (S.size() != 0)
			{
				int top = S.top();
				S.pop();
				for (int j = 0; j <pV; j++)
				{
					if((pArr[top][j] == 1) && !visited[j])
					{
						S.push(j);
						visited[j] = true;
					}
				}
			}
	//	}
	//}
	int count = 0;
	for (int i = 0; i < pV; i++)
	{
		if (visited[i] == true)
		{
			cout<<i+1<<" ";
			count++;
		}
		cout<<endl;
	}
	if (count == pV)
		cout<<"Connected graph\n";
	else
		cout<<"Gaph is not connected\n";
}
