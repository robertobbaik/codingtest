#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> graph(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if(graph[i][k] != 0 && graph[k][j] != 0)
				{
					graph[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}