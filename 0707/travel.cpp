#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
bool bfs(vector<vector<int>> &graph, int start, int end)
{
    queue<int> q;
    vector<bool> visited(N + 1, false);
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        if (n == end)
        {
            return true;
        }

        for (int i = 1; i < N + 1; i++)
        {
            if (n == i)
                continue;

            if (graph[n][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("travel.txt", "r", stdin);

    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            cin >> graph[i][j];
        }
    }

    vector<int> path(M);

    for (int i = 0; i < M; i++)
    {
        cin >> path[i];
    }

    for (int i = 1; i < M; i++)
    {
        if (!bfs(graph, path[i - 1], path[i]))
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}