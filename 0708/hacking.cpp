#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(const vector<vector<int>>& graph, int start, int N)
{
    int connect = 0;
    queue<int> q;
    vector<bool> visited(N + 1, false);

    q.push(start);
    visited[start] = true;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();

        for(int num : graph[n])
        {
            if(!visited[num])
            {
                connect++;
                visited[num] = true;
                q.push(num);
            }
        }
    }

    return connect;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("hacking.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> graph(N + 1);

    for(int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;

        graph[B].push_back(A);
    }

    vector<int> connectCount(N + 1);

    for(int i = 1; i < N + 1; i++)
    {
        int n = bfs(graph, i, N);
        connectCount[i] = n;
    }

    int max_num = *max_element(connectCount.begin(), connectCount.end());

    vector<int> result;

    for(int i = 0; i < N + 1; i++)
    {
        if(max_num == connectCount[i])
        {
            result.push_back(i);
        }
    }

    sort(result.begin(), result.end());

    for(int n : result)
    {
        cout << n << " ";
    }


    return 0;
}