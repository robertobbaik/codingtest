#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dijkstra(const vector<vector<int>> &graph, int N)
{
    vector<vector<int>> cost(N, vector<int>(N, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    pq.push({0, 0, graph[0][0]});
    cost[0][0] = graph[0][0];

    while (!pq.empty())
    {
        auto [x, y, c] = pq.top();
        pq.pop();

        if (cost[x][y] < c)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                int newCost = c + graph[nx][ny];

                if (cost[nx][ny] > newCost)
                {
                    cost[nx][ny] = newCost;
                    pq.push({nx, ny, newCost});
                }
            }
        }
    }

    return cost[N - 1][N - 1];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("4485.txt", "r", stdin);

    int num = 1;
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
            break;

        vector<vector<int>> graph(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> graph[i][j];
            }
        }

        int result = dijkstra(graph, N);

        cout << "Problem " << num << ": " << result << "\n";
        num++;
    }

    return 0;
}