#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int max_count = 0;

void dfs(const vector<vector<int>> &graph, const vector<int> &info, vector<bool> &visited, int start, int sheep, int wolf)
{
    if (sheep <= wolf)
    {
        return;
    }
    max_count = max(max_count, sheep);

    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i])
        {
            for (int next : graph[i])
            {
                if (!visited[next])
                {
                    visited[next] = true;

                    int new_sheep = sheep;
                    int new_wolf = wolf;

                    if (info[next] == 0)
                    {
                        new_sheep++;
                    }
                    else
                    {
                        new_wolf++;
                    }

                    dfs(graph, info, visited, next, new_sheep, new_wolf);

                    visited[next] = false;
                }
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    int answer = 0;

    int len = info.size();
    vector<vector<int>> graph(len);

    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        graph[a].push_back(b);
    }

    vector<bool> visited(len, false);

    visited[0] = true;

    dfs(graph, info, visited, 0, 1, 0);

    return max_count;
}

int main(void)
{
    int result = solution({0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}});

    cout << result << endl;

    return 0;
}