#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> distance(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i < N + 1; i++)
	{
		distance[i][i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		distance[A][B] = 1;
		distance[B][A] = 1;
	}

	for (int k = 1; k < N + 1; k++)
	{
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if(distance[i][k] != INF && distance[k][j] != INF)
				{
					distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
				}
			}
		}
	}

	int prev_sum = INF;

	int answer = INF;
	
	for(int i = 1; i < N; i++)
	{
		int sum = accumulate(distance[i].begin() + 1, distance[i].end(), 0);
		if(sum < prev_sum)
		{
			answer = i;
			prev_sum = sum;
		}
	}

	cout << answer << endl;

	return 0;
}