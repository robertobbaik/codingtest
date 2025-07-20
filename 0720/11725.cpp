#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> graph(N + 1);
	vector<bool> visited(N + 1);
	vector<int> answer(N + 1, 0);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int n : graph[current])
		{
			if (!visited[n])
			{
				visited[n] = true;
				answer[n] = current;
				q.push(n);
			}
		}
	}

	for(int i = 2; i < N + 1; i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}