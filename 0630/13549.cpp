#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("13549.txt", "r", stdin);

    int N, K;

    cin >> N >> K;

    vector<int> distance(100001, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[N] = 0;
    pq.push({0, N});

    while (!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        cout << currentNode << endl;

        if (currentNode == K)
        {
            cout << distance[K] << endl;
            return 0;
        }

        if (currentDistance > distance[currentNode])
            continue;

        if (currentNode - 1 >= 0 && distance[currentNode - 1] > currentDistance + 1)
        {
            distance[currentNode - 1] = currentDistance + 1;
            pq.push({currentDistance + 1, currentNode - 1});
        }

        if (currentNode + 1 <= 100000 && distance[currentNode + 1] > currentDistance + 1)
        {
            distance[currentNode + 1] = currentDistance + 1;
            pq.push({currentDistance + 1, currentNode + 1});
        }

        if (currentNode * 2 <= 100000 && distance[currentNode * 2] > currentDistance)
        {
            distance[currentNode * 2] = currentDistance;
            pq.push({currentDistance, currentNode * 2});
        }
    }

    return 0;
}