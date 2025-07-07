#include <iostream>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(const vector<string> &board, int startx, int starty, int N, int M)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<tuple<int, int, int>> q;
    q.push({startx, starty, 0});
    visited[startx][starty] = true;
    int dist = 0;

    while (!q.empty())
    {
        auto [x, y, time] = q.front();
        q.pop();

        dist = max(dist, time);

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (!visited[nx][ny] && board[nx][ny] == 'L')
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, time + 1});
                }
            }
        }
    }

    return dist;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("treasure.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    vector<string> board(N);

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    int max_dist = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'L')
            {
                max_dist = max(max_dist, bfs(board, i, j, N, M));
            }
        }
    }

    cout << max_dist << endl;

    return 0;
}