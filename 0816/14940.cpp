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

	pair<int, int> start = {0, 0};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				start = {i, j};
			}
		}
	}

	vector<vector<int>> distance(n, vector<int>(m, 0));

	queue<tuple<int, int, int>> q;

	q.push({start.first, start.second, 0});

	while (!q.empty())
	{
		auto [x, y, d] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (board[nx][ny] == 1)
				{
					board[nx][ny] = 0;
					distance[nx][ny] = d + 1;
					q.push({nx, ny, d + 1});
				}
			}
		}
	}

	for(vector<int> v : distance)
	{
		for(int n : v)
		{
			cout << n << " ";
		}

		cout << endl;
	}

	return 0;
}