#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int N, M;
int max_weight = 0;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;

bool canReach(int start, int end, int weight)
{
    visited.assign(N + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == end)
        {
            return true;
        }

        for(auto [next, capacity] : graph[node])
        {
            if(!visited[next] && capacity >= weight)
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("truck.txt", "r", stdin);

    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int A, B, C;

        cin >> A >> B >> C;

        graph[A].push_back({B, C});
        graph[B].push_back({A, C});

        max_weight = max(max_weight, C);
    }

    int start, end;
    cin >> start >> end;

    int left = 1;
    int right = max_weight;
    int answer = 0;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(canReach(start, end, mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << endl;


    return 0;
}