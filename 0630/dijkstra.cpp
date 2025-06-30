#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;

    pq.push({0, start});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto [v, w] : graph[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main(void)
{
    vector<vector<pair<int, int>>> graph(4);
    graph[0] = {{1, 140}, {2, 300}}; 
    graph[1] = {{2, 120}, {3, 200}}; 
    graph[2] = {{3, 100}};
    graph[3] = {{2, 100}, {1, 200}};         

    vector<int> distances = dijkstra(3, graph);
    cout << distances[0] << endl;

    return 0;
}