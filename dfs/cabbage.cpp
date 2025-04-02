#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(const vector<vector<int>> graph, vector<vector<bool>> &visited, int x, int y, int n, int m)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < m)
        {
            if (graph[ny][nx] == 1 && !visited[ny][nx])
            {
                dfs(graph, visited, nx, ny, n, m);
            }
        }
    }
}

void printgraph(const vector<vector<int>> graph)
{
    for (const auto &v : graph)
    {
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    cout << "===================" << endl;
}

int main(void)
{
    freopen("cabbage.txt", "r", stdin);

    int t = 0;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int m, n, k;

        cin >> m >> n >> k;

        vector<vector<int>> graph(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int j = 0; j < k; j++)
        {
            int x, y;

            cin >> x >> y;
            graph[y][x] = 1;
        }

        printgraph(graph);

        int worm_count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j] == 1 && !visited[i][j])
                {
                    dfs(graph, visited, j, i, n, m);
                    worm_count++;
                }
            }
        }

        cout << worm_count << endl;

        graph.clear();
    }

    return 0;
}