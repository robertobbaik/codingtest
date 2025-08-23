#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = str[j] - '0';
		}
	}
	
	queue<tuple<int, int, int>> q;
	q.push({0, 0, 1});
	visited[0][0] = true;

	while (!q.empty())
	{
		auto [x, y, count] = q.front();
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			cout << count << endl;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (!visited[nx][ny] && board[nx][ny] == 1)
				{
					visited[nx][ny] = true;
					q.push({nx, ny, count + 1});
				}
			}
		}
	}

	return 0;
}