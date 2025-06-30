#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>> graph, int start, int N)
{
    vector<int> distance(N + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (distance[currentNode] < currentDistance)
            continue;

        for (auto [neigborNode, cost] : graph[currentNode])
        {
            int newDistance = currentDistance + cost;
            if (distance[neigborNode] > newDistance)
            {
                distance[neigborNode] = newDistance;
                pq.push({newDistance, neigborNode});
            }
        }
    }

    return distance;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1504.txt", "r", stdin);

    int N, E;

    cin >> N >> E;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist1 = dijkstra(graph, 1, N);
    vector<int> distV1 = dijkstra(graph, v1, N);
    vector<int> distV2 = dijkstra(graph, v2, N);

    long long path1 = (long long)dist1[v1] + distV1[v2] + distV2[N];
    long long path2 = (long long)dist1[v2] + distV2[v1] + distV1[N];

    long long result = min(path1, path2);

    if(result >= INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }
    return 0;
}