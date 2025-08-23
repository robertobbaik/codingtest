#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int current)
{
	visited[current] = true;

	for(int next : graph[current])
	{
		if(!visited[next])
		{
			dfs(graph, visited, next);
		}
	}
}

int main()
{
	int N, M;

	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	vector<bool> visited(N + 1, false);

	for(int i = 0; i < M; i++)
	{
		int u, v;

		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int connected = 0;

	for(int i = 1; i < N + 1; i++)
	{
		if(!visited[i])
		{
			connected++;
			dfs(graph, visited, i);
		}
	}

	cout << connected << endl;

	return 0;
}