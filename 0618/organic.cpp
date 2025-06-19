#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y, int N, int M)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            if (!visited[nx][ny] && board[nx][ny] == 1)
            {
                dfs(board, visited, nx, ny, N, M);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("organic.txt", "r", stdin);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int M, N, K;

        cin >> M >> N >> K;

        vector<vector<int>> board(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        for (int j = 0; j < K; j++)
        {
            int X, Y;

            cin >> X >> Y;
            board[Y][X] = 1;
        }

        int count = 0;

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (board[j][k] == 1 && !visited[j][k])
                {
                    count++;
                    dfs(board, visited, j, k, N, M);
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}