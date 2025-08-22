#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(const vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y, int M, int N)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N)
		{
			if (!visited[nx][ny] && board[nx][ny] == 1)
			{
				dfs(board, visited, nx, ny, M, N);
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int M, N, K;

		cin >> M >> N >> K;

		vector<vector<int>> board(M, vector<int>(N, 0));
		vector<vector<bool>> visited(M, vector<bool>(N, false));

		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;

			board[x][y] = 1;
		}

		int count = 0;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && board[i][j] == 1)
				{
					dfs(board, visited, i, j, M, N);
					count++;
				}
			}
		}

		cout << count << endl;
	}
	return 0;
}