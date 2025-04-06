#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>> &graph, vector<int>& v, vector<bool> &visited, int node)
{
    v[node] = 1;
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (!visited[graph[node][i]])
        {
            dfs(graph, v, visited, graph[node][i]);
        }
    }
}

int main(void)
{
    freopen("pathfind.txt", "r", stdin);

    int N;

    cin >> N;

    vector<vector<int>> graph(N);

    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            if (num == 1)
            {
                temp.push_back(j);
            }
        }
        graph[i] = temp;
    }

    vector<vector<int>> result;

    for (int i = 0; i < graph.size(); i++)
    {
        vector<int> temp(N, 0);
        vector<bool> visited(N, false);
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!visited[i])
            {
                dfs(graph, temp, visited, graph[i][j]);
            }
        }
        result.push_back(temp);
    }

    for (const auto &v : result)
    {
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}