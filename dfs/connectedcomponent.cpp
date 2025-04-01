#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> uv;
vector<bool> visited;
int result = 0;

void dfs(int start)
{
    visited[start] = true;

    for (int n : uv[start])
    {
        if (!visited[n])
        {
            result++;
            dfs(n);
        }
    }
}

int main(void)
{
    freopen("connectedcomponent.txt", "r", stdin);

    cin >> N >> M;
    uv.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << u << " " << v << endl;
        uv[u].push_back(v);
        uv[v].push_back(u);
    }

    for (const auto &v : uv)
    {
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    dfs(1);

    cout << "-------------" << endl;
  
    cout <<result << endl;
    return 0;
}
