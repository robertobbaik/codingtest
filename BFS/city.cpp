#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("city.txt", "r", stdin);
    int N, M, K, X;

    cin >> N >> M >> K >> X;

    vector<vector<int>> roads(N + 1);

    for (int i = 0; i < M; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        roads[temp1].push_back(temp2);
    }

    queue<pair<int, int>> q;
    vector<int> answer;
    vector<bool> visited(N + 1, false);

    q.push({X, 0});
    visited[X] = true;

    while (!q.empty())
    {
        auto [start, distance] = q.front();

        q.pop();

        if (distance == K)
        {
            answer.push_back(start);
        }
        else
        {
            for (int i = 0; i < roads[start].size(); i++)
            {
                int next = roads[start][i];
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push({next, distance + 1});
                }
            }
        }
    }

    if (answer.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        sort(answer.begin(), answer.end());

        for (int n : answer)
        {
            cout << n << endl;
        }
    }

    return 0;
}