#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));

	while(true)
	{
		int a, b;
		cin >> a >> b;

		if(a == -1) break;

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for(int i = 1; i < N + 1; i++)
	{
		graph[i][i] = 0;
	}

	for(int k = 1; k < N + 1; k++)
	{
		for(int i = 1; i < N + 1; i++)
		{
			for(int j = 1; j < N + 1; j++)
			{
				if(graph[i][k] != INF && graph[k][j])
				{
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}

	vector<int> result(N + 1);

	for(int i = 1; i < N + 1; i++)
	{
		result[i] = *max_element(graph[i].begin() + 1, graph[i].end());
	}

	int max_num = *min_element(result.begin() + 1, result.end());
	int max_count = 0;
	vector<int> temp;
	for(int i = 1; i < N + 1; i++)
	{
		if(result[i] == max_num)
		{
			temp.push_back(i);
		}
	}

	cout << max_num << " " << temp.size() << endl;

	for(int n : temp)
	{
		cout << n << " ";
	}


	return 0;
}