#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(const vector<vector<pair<int, int>>> &graph, int N)
{
    vector<int> dist(N + 1, INF);

    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [currentCost, currentNode] = pq.top();
        pq.pop();

        if (dist[currentNode] < currentCost)
            continue;

        for (auto &[neighborNode, cost] : graph[currentNode])
        {
            int newCost = currentCost + cost;

            if (dist[neighborNode] > newCost)
            {
                dist[neighborNode] = newCost;
                pq.push({newCost, neighborNode});
            }
        }
    }

    return dist;
}

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        // bool found = false;
        // for (auto &edge : graph[a])
        // {
        //     if (edge.first == b)
        //     {
        //         edge.second = min(edge.second, c);
        //         found = true;
        //         break;
        //     }
        // }
        // if (!found)
        // {
        //     graph[a].push_back({b, c});
        // }

        // found = false;
        // for (auto &edge : graph[b])
        // {
        //     if (edge.first == a)
        //     {
        //         edge.second = min(edge.second, c);
        //         found = true;
        //         break;
        //     }
        // }
        // if (!found)
        // {
        //     graph[b].push_back({a, c});
        // }
    }

    vector<int> result = dijkstra(graph, N);

    for (int i = 1; i <= N; i++)
    {
        if (result[i] <= K)
        {
            answer++;
        }
    }

    return answer;
}

int main(void)
{
    int result = solution(6, {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}, 4);
    cout << result << endl;
    return 0;
}