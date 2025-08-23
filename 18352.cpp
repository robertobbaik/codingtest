#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, K, X;

	cin >> N >> M >> K >> X;

	vector<vector<int>> graph(N + 1);
	queue<pair<int, int>> q;
	vector<bool> visited(N + 1);
	vector<int> result;

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;

		graph[start].push_back(end);
	}

	q.push({X, 0});
	visited[X] = true;
	while (!q.empty())
	{
		auto [node, count] = q.front();

		q.pop();

		if (count == K)
		{
			result.push_back(node);

			continue;
		}

		for (int next : graph[node])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push({next, count + 1});
			}
		}
	}

	if (result.size() > 0)
	{
		sort(result.begin(), result.end());

		for (int n : result)
		{
			cout << n << "\n";
		}
	}
	else
	{
		cout << -1 << endl;
	}

	return 0;
}