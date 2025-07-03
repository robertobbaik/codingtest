#include <iostream>
#include <vector>

using namespace std;

int dfs(const vector<vector<int>>& board, int N, int M, int wallCount)
{
    

    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("virus.txt", "r", stdin);

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

    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(3, false)));

    return 0;
}