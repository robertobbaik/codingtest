#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int result = 0;

void checkExtraShape(vector<vector<int>> &board, int x, int y, int N, int M)
{
    if (x >= 0 && x + 1 < N && y - 1 >= 0 && y + 1 < M)
    {
        int sum = board[x][y] + board[x + 1][y] + board[x][y - 1] + board[x][y + 1];
        result = max(result, sum);
    }
    if (x - 1 >= 0 && x + 1 < N && y + 1 < M)
    {
        int sum = board[x][y] + board[x - 1][y] + board[x + 1][y] + board[x][y + 1];
        result = max(result, sum);
    }
    if (x - 1 >= 0 && x < N && y - 1 >= 0 && y + 1 < M)
    {
        int sum = board[x][y] + board[x - 1][y] + board[x][y - 1] + board[x][y + 1];
        result = max(result, sum);
    }
    if (x - 1 >= 0 && x + 1 < N && y - 1 >= 0)
    {
        int sum = board[x][y] + board[x - 1][y] + board[x + 1][y] + board[x][y - 1];
        result = max(result, sum);
    }
}

void dfs(vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y, int N, int M, int depth, int num)
{
    num += board[x][y];

    if (depth == 4)
    {
        result = max(result, num);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            if (!visited[nx][ny])
            {
                visited[x][y] = true;
                dfs(board, visited, nx, ny, N, M, depth + 1, num);
                visited[x][y] = false;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("Tetromino.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int max = 0;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = true;
            dfs(board, visited, i, j, N, M, 1, 0);
            visited[i][j] = false;

            checkExtraShape(board, i, j, N, M);
        }
    }

    cout << result << endl;

    return 0;
}