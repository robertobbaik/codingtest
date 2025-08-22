#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(const vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y, int n, int m)
{
	visited[x][y] = true;

	int area = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (board[nx][ny] == 1 && !visited[nx][ny])
			{
				area += dfs(board, visited, nx, ny, n, m);
			}
		}
	}

	return area;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int count = 0;
	int max_area = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && board[i][j] == 1)
			{
				count++;
				int currentArea = dfs(board, visited, i, j, n, m);
				max_area = max(currentArea, max_area);
			}
		}
	}

	cout << count << endl;
	cout << max_area << endl;

	return 0;
}