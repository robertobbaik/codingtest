#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("RotateArray.txt", "r", stdin);

    int N, M, R;

    cin >> N >> M >> R;

    vector<vector<int>> board(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j == 0)
            {
                if (i == N - 1)
                {
                }
                else
                {
                }
            }
        }
    }

    return 0;
}

// 0,0 0,1 0,2 0,3
// 1,0 1,1 1,2 1,3
// 2,0 2,1 2,2 2,3
// 3,0 3,1 3,2 3,3

// y == 0 x + 1
// x == N-1 y + 1
// y == M-1 x -1
//
