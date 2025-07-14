#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int cleancount = 0;

vector<vector<int>> board;

void dfs(int x, int y, int direction)
{
    if (board[x][y] == 0)
    {
        board[x][y] = -1;
        cleancount++;
    }

    bool isClean = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            if (board[nx][ny] == 0)
            {
                isClean = false;
                break;
            }
        }
    }

    if (!isClean)
    {
        for (int i = 0; i < 4; i++)
        {
            direction = (direction + 3) % 4;
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] == 0)
            {
                dfs(nx, ny, direction);
                return;
            }
        }
    }
    else
    {
        int backDir = (direction + 2) % 4;
        int nx = x + dx[backDir];
        int ny = y + dy[backDir];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 1)
        {
            dfs(nx, ny, direction); 
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int startX, startY, dir;
    cin >> startX >> startY >> dir;

    board.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    dfs(startX, startY, dir);

    cout << cleancount << endl;

    return 0;
}