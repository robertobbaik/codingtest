#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(const vector<vector<int>> &board, vector<vector<bool>> &visited, int startX, int startY)
{
    queue<tuple<int, int>> q;
    q.push({startX, startY});
    visited[startY][startX] = true;

    int area = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N)
            {
                if (!visited[ny][nx] && board[ny][nx] == 1)
                {
                    visited[ny][nx] = true;
                    q.push({nx, ny});
                    area++;
                }
            }
        }
    }

    return area;
}

int main(void)
{
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int pictureCount = 0;
    int maxArea = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && board[i][j] == 1)
            {
                pictureCount++;
                maxArea = max(maxArea, bfs(board, visited, j, i));
            }
        }
    }

    cout << pictureCount << endl;
    cout << maxArea << endl;

    return 0;
}
