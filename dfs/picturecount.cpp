#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int temp;

void dfs(const vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y, int count)
{
    temp = max(count, temp);
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = x + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N)
        {
            //cout << 2 << endl;
            if (!visited[ny][nx] && board[ny][nx] == 1)
            {
                dfs(board, visited, nx, ny, count + 1);
            }
        }
    }
}

int main(void)
{
    freopen("picturecount.txt", "r", stdin);

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

    int picturecount = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && board[i][j] == 1)
            {
                picturecount++;
                dfs(board, visited, j, i, 1);
                cout << picturecount << endl;
                
            }
        }
        cout << endl;
    }

    cout << temp << " " << picturecount << endl;

    return 0;
}