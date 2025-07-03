#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>> &graph, int start, int n)
{
    vector<int> distance(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (distance[currentNode] < currentDistance)
            continue;

        for (auto [neighborNode, nextDistance] : graph[currentNode])
        {
            int newDistance = currentDistance + nextDistance;

            if (distance[neighborNode] > newDistance)
            {
                distance[neighborNode] = newDistance;
                pq.push({newDistance, neighborNode});
            }
        }
    }

    return distance;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("floyd.txt", "r", stdin);

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;

        graph[s].push_back({e, c});
    }

    vector<vector<int>> result;

    for (int i = 1; i < n + 1; i++)
    {
        vector<int> result = dijkstra(graph, i, n);
        for (int j = 1; j <= n; j++)
        {
            if (result[j] == INT_MAX)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << result[j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}