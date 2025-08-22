#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main()
{
	int N, M, K, X;

	cin >> N >> M >> K >> X;

	vector<vector<int>> graph(N + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> distance(N + 1, INF);

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;

		graph[start].push_back(end);
	}

	distance[X] = 0;

	pq.push({X, 0});

	while(!pq.empty())
	{
		auto [dist, startNode] = pq.top();
		pq.pop();

		
	}

	
	return 0;
}