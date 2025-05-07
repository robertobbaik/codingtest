#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    int N, M, fuel;

    cin >> N >> M >> fuel;

    vector<vector<int>> board(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    int x, y;

    cin >> x, y;

    vector<vector<int>> move;

    for (int i = 0; i < M; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 4; j++)
        {
            int n;
            cin >> n;
            temp.push_back(n);
        }

        move.push_back(temp);
    }

    while (M--)
    {
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        queue<pair<int, int>> q;
        q.push({x, y});

        while (!q.empty())
        {
            auto [col, row] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = row + dx[i];
                int ny = col + dy[i];
            }
        }
    }
}