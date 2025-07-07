#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lineup.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> graph(N +  1);
    vector<int> indegree(N + 1, 0);

    for(int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;

    for(int i = 1; i < N + 1; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> result;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for(int next : graph[current])
        {
            indegree[next]--;
            if(indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if(i < result.size() - 1)
        {
            cout << " ";
        }
    }

    cout << "\n";


    return 0;
}