#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
    visited[node] = true;
    cout << node << " ";
    for (int n : graph[node])
    {
        if (!visited[n])
        {
            dfs(graph, visited, n);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("dfsbfs.txt", "r", stdin);

    int N, M, V;

    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(N + 1, false);

    dfs(graph, visited, V);

    cout << "\n";

    visited.assign(N + 1, false);

    queue<int> q;

    q.push(V);
    visited[V] = true;
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();

        for (int n : graph[node])
        {
            if (!visited[n])
            {
                visited[n] = true;
                q.push(n);
            }
        }
    }

    return 0;
}