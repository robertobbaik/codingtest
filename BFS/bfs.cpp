#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<pair<int, int>> graph, int start)
{
    vector<int> answer;
    // vector<vector<int>> new_graph()

    unordered_map<int, vector<int>> um;

    for (const auto &p : graph)
    {
        um[p.first].push_back(p.second);
        //um[p.second].push_back(p.first);
    }

    queue<int> q;

    vector<bool> visited(um.size(), false);
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int i = q.front();
        answer.push_back(i);
        q.pop();

        for (int n : um[i])
        {
            if (!visited[n])
            {
                visited[n] = true;
                q.push(n);
            }
        }
    }
    return answer;
}

int main(void)
{
    vector<pair<int, int>> graph = {

        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 0}
    };

    vector<int> result = solution(graph, 1);

    for (int n : result)
    {
        cout << n << " ";
    }

    return 0;
}