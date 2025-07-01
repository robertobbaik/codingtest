#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("dijkstra.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++)
    {
        int s, e, c;

        cin >> s >> e >> c;

        graph[s].push_back({e, c});
    }

    int start, end;
    cin >> start >> end;

    vector<int> distance(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    distance[start] = 0;

    while(!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if(distance[currentNode] < currentDistance) continue;

        for(auto [neigborNode, cost] : graph[currentNode])
        {
            int newDistance = currentDistance + cost;

            if(distance[neigborNode] > newDistance)
            {
                distance[neigborNode] = newDistance;
                pq.push({newDistance, neigborNode});
            }
        }
    }

    cout << distance[end] << endl;

    return 0;
}