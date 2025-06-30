#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1753.txt", "r", stdin);

    int V, E;

    cin >> V >> E;

    int start;
    cin >> start;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    vector<int> distance(V + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (distance[currentNode] < currentDistance)
            continue;

        for (auto [neigborNode, cost] : graph[currentNode])
        {
            int newDistance = distance[currentNode] + cost;

            if (newDistance < distance[neigborNode])
            {
                distance[neigborNode] = newDistance;
                pq.push({newDistance, neigborNode});
            }
        }
    }
    
    for(int i = 1; i < V + 1; i++)
    {
        if(distance[i] == INT_MAX)
        {
            cout << "INF" << "\n";
        }
        else
        {
            cout << distance[i] << "\n";
        }
    }

    return 0;
}