// https://www.acmicpc.net/problem/2638

#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(vector<vector<int>> &board, vector<pair<int, int>> &cheeze, int x, int y, int N, int M)
{
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            if (board[nx][ny] == -1)
            {
                count++;
            }
        }
    }

    if (count >= 2)
    {
        cheeze.push_back({x, y});
    }
}

void air(vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y, int N, int M)
{
    visited[x][y] = true;
    board[x][y] = -1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            if (!visited[nx][ny])
            {
                if (board[nx][ny] == 0)
                {
                    air(board, visited, nx, ny, N, M);
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("cheeze.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));

    int count = 0;
    int time = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                count++;
            }
        }
    }

    while (count > 0)
    {
        time++;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == -1)
                {
                    board[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> cheeze;
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        air(board, visited, 0, 0, N, M);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == 1)
                {
                    dfs(board, cheeze, i, j, N, M);
                }
            }
        }

        for (pair<int, int> p : cheeze)
        {
            auto [x, y] = p;
            board[x][y] = 0;
            count--;
        }
    }

    cout << time << endl;

    return 0;
}