#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1261.txt", "r", stdin);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> maze(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++)
        {
            maze[i][j] = str[j] - '0';
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<int>> distance(N, vector<int>(M, INT_MAX));

    distance[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty())
    {
        auto [x, y, cost] = pq.top();
        pq.pop();

        if (distance[x][y] < cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                int newCost = cost + maze[nx][ny];
                if (distance[nx][ny] > newCost)
                {
                    distance[nx][ny] = newCost;
                    pq.push({nx, ny, newCost});
                }
            }
        }
    }

    cout << distance[N - 1][M - 1] << endl;

    return 0;
}