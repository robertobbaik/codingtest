#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <numeric>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start)
{
    vector<int> distance(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    distance[start] = 0;

    while(!pq.empty())
    {
        auto [currentCost, currentNode] = pq.top();
        pq.pop();
        
        if(distance[currentNode] < currentCost) continue;

        for(auto [neighborNode, cost] : graph[currentNode])
        {
            int newCost = cost + currentCost;

            if(distance[neighborNode] > newCost)
            {
                distance[neighborNode] = newCost;
                pq.push({newCost, neighborNode});
            }
        }
    }

    return distance;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("connectnetwork.txt", "r", stdin);

    cin >> N >> M;
    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int min_cost = INT_MAX;

    for(int i = 1; i < N + 1; i++)
    {
        vector<int> cost = dijkstra(graph, i);
        int sum = accumulate(cost.begin() + 1, cost.end(), 0);

        min_cost = min(min_cost, sum);
    }

    cout << min_cost << endl;

    return 0;
}