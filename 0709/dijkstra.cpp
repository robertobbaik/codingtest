#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <numeric>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;

int dijkstra(int start)
{
    vector<int> costs(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});

    costs[start] = 0;

    while (!pq.empty())
    {
        auto [currentCost, currentNode] = pq.top();
        pq.pop();

        if (costs[currentNode] < currentCost)
            continue;

        for (auto [neighborNode, cost] : graph[currentNode])
        {
            int newCost = currentCost + cost;

            if (costs[neighborNode] > newCost)
            {
                costs[neighborNode] = newCost;
                pq.push({newCost, neighborNode});
            }
        }
    }

    return accumulate(costs.begin() + 1, costs.end(), 0);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("dijkstra.txt", "r", stdin);

    cin >> N >> M;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int result = INT_MAX;
    for (int i = 1; i < N + 1; i++)
    {
        int n = dijkstra(i);

        result = min(result, n);
    }

    cout << result << endl;

    return 0;
}