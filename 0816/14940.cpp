#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(vector<vector<int>> &board)
{
}

int main()
{
	int n, m;

	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m, 0));
	vector<vector<int>> distance(n, vector<int>(m, -1));
	pair<int, int> start = {0, 0};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				start = {i, j};
				distance[i][j] = 0;
			}
			else if (board[i][j] == 0)
			{
				distance[i][j] = 0;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(start);

	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (board[nx][ny] == 1 && distance[nx][ny] == -1)
				{
					distance[nx][ny] = distance[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
	}

	for (vector<int> v : distance)
	{
		for (int n : v)
		{
			cout << n << " ";
		}

		cout << endl;
	}

	return 0;
}