#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, M;

vector<vector<bool>> visited;

void bfs(const vector<vector<int>> &board, vector<vector<int>> &tempboard, int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N)
        {
            if (board[ny][nx] == 0)
            {
                tempboard[y][x]++;
            }
        }
    }
}

void dfs(const vector<vector<int>> &board, int x, int y)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N)
        {
            if (!visited[ny][nx] && board[ny][nx] > 0)
            {
                dfs(board, nx, ny);
            }
        }
    }
}

int main(void)
{
    freopen("iceberg.txt", "r", stdin);
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int count = 0;
    int year = 0;
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         if (board[i][j] > 0 && !visited[i][j])
    //         {
    //             count++;
    //             dfs(board, j, i);
    //         }
    //     }
    // }

    while (count < 2)
    {
        year++;
        vector<vector<int>> tempboard(N, vector<int>(M, 0));
        visited.assign(N, vector<bool>(M, false));

        int zerocount = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] > 0)
                {
                    zerocount++;
                    bfs(board, tempboard, j, i);
                }
            }
        }

        if(zerocount == 0)
        {
            year = 0;
            break;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int n = board[i][j] - tempboard[i][j];
                if (n < 0)
                {
                    n = 0;
                }
                board[i][j] = n;
            }
        }

        count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] > 0 && !visited[i][j])
                {
                    count++;
                    dfs(board, j, i);
                }
            }
        }
    }

    cout << year << endl;

    return 0;
}