#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<bool> visited;
int max_dist = 0;
int farthest_node = 1;

void dfs(int node, int dist)
{
	visited[node] = true;

	if (dist > max_dist)
	{
		max_dist = dist;
		farthest_node = node;
	}

	for (auto &edge : tree[node])
	{
		int next = edge.first;
		int weight = edge.second;

		if (!visited[next])
		{
			dfs(next, dist + weight);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	tree.assign(n + 1, vector<pair<int, int>>());
	visited.assign(n + 1, false);

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;

		int edge, weight;
		cin >> edge >>  weight;

		tree[v].push_back({edge, weight});
		tree[edge].push_back({v, weight});
	}

	dfs(1, 0);

	visited.assign(n + 1, false);
	max_dist = 0;
	dfs(farthest_node, 0);

	cout << max_dist << '\n';

	return 0;
}