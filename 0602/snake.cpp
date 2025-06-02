#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main(void)
{
    freopen("snake.txt", "r", stdin);
    int N, M;

    cin >> N >> M;
    unordered_map<int, int> um;
    for (int i = 0; i < N + M; i++)
    {
        int start, end;
        cin >> start >> end;

        um[start] = end;
    }

    queue<pair<int, int>> q;
    vector<bool> visited(100, false);
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty())
    {
        auto [pos, depth] = q.front();
        q.pop();

        if (pos == 100)
        {
            cout << depth << endl;
            break;
        }

        for (int i = 1; i <= 6; i++)
        {
            if (pos + i <= 100)
            {
                auto it = um.find(pos + i);

                if (it != um.end())
                {
                    if (!visited[um[pos + i]])
                    {
                        visited[um[pos + i]] = true;
                        q.push({um[pos + i], depth + 1});
                    }
                }
                else
                {
                    if (!visited[pos + i])
                    {
                        visited[pos + i] = true;
                        q.push({pos + i, depth + 1});
                    }
                }
            }
        }
    }

    return 0;
}