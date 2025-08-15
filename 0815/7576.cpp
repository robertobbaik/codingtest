#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
	cin >> M >> N;

	vector<vector<int>> board(N, vector<int>(M, 0));
	queue<tuple<int, int, int>> q;
	int zeroCount = 0;
	int day = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				zeroCount++;
			}
			else if(board[i][j] == 1)
			{
				q.push({i, j, 0});
			}
		}
	}

	if (zeroCount == 0)
	{
		cout << "0" << endl;
		return 0;
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
					board[nx][ny] = 1;
					zeroCount--;

					q.push({nx, ny, t + 1});
				}
			}
		}
	}

	if (zeroCount > 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << day << endl;
	}

	return 0;
}