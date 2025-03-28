#include <vector>
#include <iostream>

using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &visitOrder)
{
    visited[node] = true;
    visitOrder.push_back(node); // 방문 순서 저장

    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(i, graph, visited, visitOrder);
        }
    }
}

vector<int> solution(int n, vector<vector<int>> computers, int start)
{
    vector<bool> visited(n, false);
    vector<int> visitOrder;

    dfs(start, computers, visited, visitOrder);

    return visitOrder;
}

int main(void)
{
    cout << "Hello, DFS" << endl;

    int n = 5;
    vector<vector<int>> computers = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}};
    int start = 0;

    vector<int> result = solution(n, computers, start);
    for (int node : result)
    {
        cout << node << " ";
    }

    return 0;
}