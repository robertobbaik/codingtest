#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, E;

	cin >> N >> E;

	vector<vector<int>> distance(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i < N + 1; i++)
	{
		distance[i][i] = 0;
	}

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		distance[a][b] = c;
		distance[b][a] = c;
	}

	for (int k = 1; k < N + 1; k++)
	{
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if (distance[i][k] != INF && distance[k][j] != INF)
				{
					distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
				}
			}
		}
	}

	int v1, v2;
	cin >> v1 >> v2;

	long long path1 = distance[1][v1] + distance[v1][v2] + distance[v2][N];
	long long path2 = distance[1][v2] + distance[v2][v1] + distance[v1][N];

	long long result = min(path1, path2);

	if (result >= INF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << result << endl;
	}

	return 0;
}