#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>> &graph, vector<bool> &visited, int start)
{
	visited[start] = true;
	cout << start << " ";
	for (int n : graph[start])
	{
		if (!visited[n])
		{
			visited[n] = true;
			dfs(graph, visited, n);
		}
	}
}

void bfs(const vector<vector<int>> &graph, int start)
{
	vector<bool> visited(graph.size(), false);

	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		cout << n << " ";
		for (int next : graph[n])
		{
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}
	}
}
int main()
{
	int N, M, V;

	cin >> N >> M >> V;

	vector<vector<int>> graph(N + 1);

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;

		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 1; i < N + 1; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	vector<bool> visited(N + 1, false);

	dfs(graph, visited, V);

	cout << endl;

	bfs(graph, V);
	return 0;
}