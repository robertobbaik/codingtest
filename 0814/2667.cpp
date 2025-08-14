#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N;

void dfs(const vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y, int& count)
{
	visited[x][y] = true;
	count++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		{
			if (!visited[nx][ny] && graph[nx][ny] == 1)
			{
				dfs(graph, visited, nx, ny, count);
			}
		}
	}
}

int main()
{
	cin >> N;

	vector<vector<int>> graph(N, vector<int>(N, 0));
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < N; j++)
		{
			graph[i][j] = str[j] - '0';
		}
	}

	vector<int> arr;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && graph[i][j] == 1)
			{
				int count = 0;
				dfs(graph, visited, i, j, count);

				if(count > 0)
				{
					arr.push_back(count);
				}
			}
		}
	}

	sort(arr.begin(), arr.end());

	cout << arr.size() << endl;

	for(int n : arr)
	{
		cout << n << endl;
	}

	return 0;
}