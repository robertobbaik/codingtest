#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1162.txt", "r", stdin);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<vector<long long>> distance(N + 1, vector<long long>(K + 1, LLONG_MAX));
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    distance[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        auto [currentDistance, currentNode, paved] = pq.top();
        pq.pop();

        if (currentDistance > distance[currentNode][paved])
            continue;

        for (auto [nextNode, nextCost] : graph[currentNode])
        {
            if (distance[currentNode][paved] + nextCost < distance[nextNode][paved])
            {
                distance[nextNode][paved] = distance[currentNode][paved] + nextCost;
                pq.push({distance[nextNode][paved], nextNode, paved});
            }

            if (paved < K && distance[currentNode][paved] < distance[nextNode][paved + 1])
            {
                distance[nextNode][paved + 1] = distance[currentNode][paved];
                pq.push({distance[nextNode][paved + 1], nextNode, paved + 1});
            }
        }
    }

    long long result = LLONG_MAX;
    for(int i = 0; i <= K; i++)
    {
        result = min(result, distance[N][i]);
    }

    cout << result << endl;

    return 0;
}