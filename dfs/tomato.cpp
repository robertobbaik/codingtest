#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    freopen("tomato.txt", "r", stdin);

    int M, N;

    cin >> M >> N;

    vector<vector<int>> board(N, vector<int>(M, 0));

    queue<vector<int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    int count = 0;
    int temp_count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 1)
            {
                q.push({i, j, 0});
            }
            else if(board[i][j] == 0)
            {
                temp_count++;
            }
        }
    }

    if(temp_count == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    while (!q.empty())
    {
        vector<int> temp = q.front();
        int x = temp[0];
        int y = temp[1];
       
        count = temp[2];
        
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (board[nx][ny] == 0)
                {
                    board[nx][ny] = 1;
                    
                    q.push({nx, ny, count + 1});
                    temp_count--;
                }
            }
        }
    }

    cout << (temp_count == 0 ? count : -1) << endl;

    return 0;
}