#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int dijkstra(const vector<vector<pair<int, int>>> &graph, int start, int end, int N)
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
            if (newDistance < distance[neigborNode])
            {
                distance[neigborNode] = newDistance;
                pq.push({newDistance, neigborNode});
            }
        }
    }

    return distance[end];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1238.txt", "r", stdin);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({e, c});
    }

    vector<int> distance(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int dis = dijkstra(graph, i, X, N) + dijkstra(graph, X, i, N);
        distance[i] = dis;
    }

    int max = *max_element(distance.begin(), distance.end());

    cout << max << endl;

    return 0;
}