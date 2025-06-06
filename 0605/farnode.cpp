#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    map<int, vector<int>, greater<int>> um;

    for (int i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    um[0].push_back(1);

    while(!q.empty())
    {
        auto [node, depth] = q.front();
        q.pop();

        for(int i = 0; i < graph[node].size(); i++)
        {
            int nnode = graph[node][i];

            if(!visited[nnode])
            {
                q.push({nnode, depth + 1});
                visited[nnode] = true;
                um[depth + 1].push_back(nnode);
            }
        }
    }

    auto it = um.begin();

    answer = it->second.size();


    return answer;
}

int main(void)
{
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    int result = solution(6, edge);

    cout << result << endl;

    return 0;
}