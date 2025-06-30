#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("minexpense.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++)
    {
        int s, d, p;
        cin >> s >> d >> p;

        graph[s].push_back(make_pair(d, p));
    }

    int start, end;
    cin >> start >> end;

    vector<int> distance(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    distance[start] = 0;

    pq.push({0, start});

    while(!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if(currentDistance > distance[currentNode]) continue;

        for(auto [neighborNode, cost] : graph[currentNode])
        {
            int newDistance = distance[currentNode] + cost;

            if(newDistance < distance[neighborNode])
            {
                distance[neighborNode] = newDistance;
                pq.push({newDistance, neighborNode});
            }
        }
    }

    cout << distance[end] << endl;

    return 0;
}