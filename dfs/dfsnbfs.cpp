#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int N, M, start;

void dfs(int start)
{
    visited.resize(N + 1, false);
    visited[start] = true;
    cout << start << " ";
    for (int n : graph[start])
    {
        if (!visited[n])
        {
            dfs(n);
        }
    }
}

void bfs(int start)
{
    vector<bool> visited_bfs(visited.size(), false);
    queue<int> q;

    visited_bfs[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int i = q.front();
        
        q.pop();
        cout << i << " ";
        
        for (int n : graph[i])
        {
            if (!visited_bfs[n])
            {
                visited_bfs[n] = true;
                q.push(n);
            }
        }
    }
}

int main(void)
{
    freopen("dfsnbfs.txt", "r", stdin);

    cin >> N >> M >> start;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto &v : graph)
    {
        sort(v.begin(), v.end());
    }

    dfs(start);
    cout << endl;
    bfs(start);
}
