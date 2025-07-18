#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(const vector<vector<pair<int, int>>> &graph, int start, int N)
{
	vector<int> dist(N + 1, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;

	pq.push({0, start});

	while (!pq.empty())
	{
		auto [currentCost, currentNode] = pq.top();
		pq.pop();

		if (dist[currentNode] < currentCost)
			continue;

		for (auto &[neigborNode, cost] : graph[currentNode])
		{
			int newCost = cost + currentCost;
			if (dist[neigborNode] > newCost)
			{
				dist[neigborNode] = newCost;
				pq.push({newCost, neigborNode});
			}
		}
	}

	return dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, E;

	cin >> N >> E;

	vector<vector<pair<int, int>>> distance(N + 1);

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		distance[a].push_back({b, c});
		distance[b].push_back({a, c});
	}

	int v1, v2;
	cin >> v1 >> v2;

	vector<int> dist1 = dijkstra(distance, 1, N);
	vector<int> distv1 = dijkstra(distance, v1, N);
	vector<int> distv2 = dijkstra(distance, v2, N);

	long long path1 = (long long)dist1[v1] + distv1[v2] + distv2[N]; 
	long long path2 = (long long)dist1[v2] + distv2[v1] + distv1[N]; 

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