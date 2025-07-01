#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1162.txt", "r", stdin);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> distance(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        graph[A].push_back({B, C});
    }

    distance[1] = 0;
    pq.push({0, 1});

    while(!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if(currentDistance > distance[currentNode]) continue;

        for(auto[nextNode, nextCost] : graph[currentNode])
        {
            int newCost = currentDistance + nextCost;

            if(distance[nextNode] > newCost)
            {
                distance[nextNode] = newCost;
                pq.push({newCost, nextNode});
            }
        }
    }

    cout << distance[N] << endl;

    return 0;
}