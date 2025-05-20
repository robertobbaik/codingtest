#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void)
{
    freopen("babyshark.txt", "r", stdin);
 
    int N;

    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int startCol, startRow;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                startCol = i;
                startRow = j;
            }
        }
    }

    cout << "MIDDLE" << endl;

    int shark_size = 2;
    int total_distance = 0;

    queue<pair<pair<int, int>, int>> q;
    q.push({{startCol, startRow}, 0});
    visited[startCol][startRow] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();

        int col = p.first.first;
        int row = p.first.second;
        int distance = p.second;

        if (board[col][row] == 0 || board[col][row] == 9)
        {
            total_distance = distance;
            for (int i = 0; i < 4; i++)
            {
                int ncol = col + dx[i];
                int nrow = row + dy[i];

                if (ncol >= 0 && ncol < N && nrow >= 0 && nrow < N)
                {
                    q.push({{ncol, nrow}, distance + 1});
                    visited[ncol][nrow] = true;
                }
            }
        }
        else
        {
            if (board[col][row] <= shark_size && board[col][row] > 0)
            {
                total_distance = distance;
                visited.assign(N, vector<bool>(N, false));
                visited[col][row] = true;
                board[col][row] = -1;
                shark_size++;
                for (int i = 0; i < 4; i++)
                {
                    int ncol = col + dx[i];
                    int nrow = row + dy[i];

                    if (ncol >= 0 && ncol < N && nrow >= 0 && nrow < N)
                    {
                        q.push({{ncol, nrow}, distance + 1});
                        visited[ncol][nrow] = true;
                    }
                }
            }
        }
    }

    cout << total_distance << endl;

    return 0;
}