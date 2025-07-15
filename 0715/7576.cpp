#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	vector<vector<int>> board(N, vector<int>(M, 0));

	int zerocount = 0;
	int day = 0;

	queue<tuple<int, int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				zerocount++;
			}
			else if (board[i][j] == 1)
			{
				q.push({i, j, 0});
			}
		}
	}

	while (!q.empty())
	{
		auto [x, y, t] = q.front();
		q.pop();

		day = max(day, t);

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			{
				if (board[nx][ny] == 0)
				{
					zerocount--;
					board[nx][ny] = 1;
					q.push({nx, ny, t + 1});
				}
			}
		}
	}

	if (zerocount == 0)
	{
		cout << day << endl;
	}
	else
	{
		cout << -1 << endl;
	}

	return 0;
}