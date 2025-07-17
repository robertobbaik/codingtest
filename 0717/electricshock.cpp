#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int start, int& count)
{
    visited[start] = true;
    count++;
    for (int i = 0; i < graph[start].size(); i++)
    {
        if (!visited[graph[start][i]])
        {
            dfs(graph, visited, graph[start][i], count);
           
        }
    }
}

int gap(vector<vector<int>> &graph, int n)
{
    vector<bool> visited(n + 1, false);
    vector<int> results;
    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            int count = 0;
            dfs(graph, visited, i, count);
            results.push_back(count);
        }
    }

    int result = abs(results[0] - results[1]);

    return result;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = -1;
    vector<int> results;

    for (int i = 0; i < wires.size(); i++)
    {
        vector<vector<int>> graph(n + 1);
        for (int j = 0; j < wires.size(); j++)
        {
            if (i == j)
                continue;

            graph[wires[j][0]].push_back(wires[j][1]);
            graph[wires[j][1]].push_back(wires[j][0]);
        }

        int result = gap(graph, n);
        results.push_back(result);
    }

    answer = *min_element(results.begin(), results.end());

    return answer;
}