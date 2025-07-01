#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("5972.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> cost(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    cost[1] = 0;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [currentCost, currentNode] = pq.top();
        pq.pop();

        if (cost[currentNode] < currentCost)
            continue;

        for (auto [neigborNode, nextCost] : graph[currentNode])
        {
            int newCost = nextCost + currentCost;

            if (cost[neigborNode] > newCost)
            {
                cost[neigborNode] = newCost;
                pq.push({newCost, neigborNode});
            }
        }
    }

    cout << cost[N] << endl;

    return 0;
}