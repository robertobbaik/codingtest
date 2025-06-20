#include <iostream>
#include <vector>
#include <string>

using namespace std;

int answer = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(vector<string> &board, vector<vector<bool>> &visited, int x, int y, int depth, int s_count, int y_count)
{
    // cout << s_count << endl;
    if (depth == 7)
    {
        if (s_count >= 4)
        {
            answer++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
        {
            if (!visited[nx][ny])
            {
                s_count = board[nx][ny] == 'S' ? s_count + 1 : s_count;
                y_count = board[nx][ny] == 'Y' ? y_count + 1 : y_count;

                visited[nx][ny] = true;
                dfs(board, visited, nx, ny, depth + 1, s_count, y_count);
                visited[nx][ny] = false;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("bully.txt", "r", stdin);

    vector<string> board(5);
    vector<vector<bool>> visited(5, vector<bool>(5, false));

    for (int i = 0; i < 5; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!visited[i][j] && board[i][j] == 'S')
            {
                visited[i][j] = true;
                dfs(board, visited, i, j, 1, 1, 0);
                visited[i][j] = false;
            }
        }
    }

    cout << answer << endl;

    return 0;
}