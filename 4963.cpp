#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void dfs(const vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y, int h, int w)
{
	visited[x][y] = true;

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < h && ny >= 0 && ny < w)
		{
			if (!visited[nx][ny] && board[nx][ny] == 1)
			{
				dfs(board, visited, nx, ny, h, w);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		vector<vector<int>> board(h, vector<int>(w));
		vector<vector<bool>> visited(h, vector<bool>(w, false));

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
			}
		}

		int count = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board[i][j] == 1 && !visited[i][j])
				{
					count++;
					dfs(board, visited, i, j, h, w);
				}
			}
		}

		cout << count << "\n";
	}
	return 0;
}