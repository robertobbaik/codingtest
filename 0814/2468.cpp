#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(const vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y, int height)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		{
			if (!visited[nx][ny] && graph[nx][ny] > height)
			{
				dfs(graph, visited, nx, ny, height);
			}
		}
	}
}

int main()
{
	cin >> N;

	vector<vector<int>> graph(N, vector<int>(N, 0));
	vector<vector<bool>> visited(N, vector<bool>(N, false));

	int max_height = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
			max_height = max(max_height, graph[i][j]);
		}
	}

	int maxsafeareas = 1;

	for (int k = 1; k < max_height; k++)
	{
		visited.assign(N, vector<bool>(N, false));
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && graph[i][j] > k)
				{
					count++;
					dfs(graph, visited, i, j, k);
				}
			}
		}
		maxsafeareas = max(maxsafeareas, count);
	}

	cout << maxsafeareas << endl;

	return 0;
}