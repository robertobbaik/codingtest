#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> computers;
vector<bool> visited;

int result = 0;

void dfs(int computer)
{
    visited[computer] = true;

    for(int n : computers[computer])
    {
        if(!visited[n])
        {
            result++;
            dfs(n);
        }
    }
}



int main(void)
{
    freopen("virus.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    computers.resize(n + 1);
    visited.resize(n + 1, false);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        computers[u].push_back(v);
        computers[v].push_back(u);
    }

    for(const auto& v : computers)
    {
        for(int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }


    dfs(1);

    cout << result << endl;
    return 0;
}