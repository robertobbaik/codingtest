#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, int& count)
{
    visited[node] = true;

    for(int next : graph[node])
    {
        if(!visited[next])
        {
            count++;
            dfs(graph, visited, next, count);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("virus.txt", "r", stdin);

    int computerCount;

    cin >> computerCount;

    int network;

    cin >> network;

    vector<vector<int>> graph(computerCount + 1);

    for(int i = 0; i < network; i++)
    {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(computerCount + 1, false);

    int count = 0;

    dfs(graph, visited, 1, count);

    cout << count << endl;

    
    return 0;
}