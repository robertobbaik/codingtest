#include <iostream>
#include <vector>

using namespace std;

int networkCount = 0;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int start)
{
	visited[start] = true;

	for(int next : graph[start])
	{
		if(!visited[next])
		{
			networkCount++;
			dfs(graph, visited, next);
		}
	}
}

int main()
{
	int N, M;

	cin >> N >> M;

	vector<vector<int>> graph(N + 1);

	for(int i = 0; i < M; i++)
	{
		int a, b;

		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<bool> visited(N + 1, false);
	dfs(graph, visited, 1);

	cout << networkCount << endl;


	return 0;
}