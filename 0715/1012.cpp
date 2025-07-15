#include <iostream>
#include <vector>

using namespace std;
int M, N, K;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(const vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (!visited[nx][ny] && board[nx][ny] == 1)
			{
				visited[nx][ny] = true;
				dfs(board, visited, nx, ny);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;

		vector<vector<int>> board(N, vector<int>(M, 0));
		vector<vector<bool>> visited(N, vector<bool>(M, false));

		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;

			board[Y][X] = 1;
		}

		int wormcount = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 1 && !visited[i][j])
				{
					visited[i][j] = true;
					dfs(board, visited, i, j);
					wormcount++;
				}
			}
		}

		cout << wormcount << endl;
	}

	return 0;
}