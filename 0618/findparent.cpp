#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parent, int node)
{
    visited[node] = true;
    for(int next : graph[node])
    {
        if(!visited[next])
        {
            parent[next] = node;
            dfs(graph, visited, parent, next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("findparent.txt", "r", stdin);

    int N;
    cin >> N;

    vector<int> tree(N + 1);
    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(graph, visited, tree, 1);

    for(int i = 2; i <= N; i++)
    {
        cout << tree[i] << endl;
    }

    return 0;
}