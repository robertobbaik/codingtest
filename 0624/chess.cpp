#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getwrongcount(const vector<vector<char>>& board, int startX, int startY, char startColor)
{
    int wrongcount = 0;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            char color = ((i + j) % 2 == 0) ? startColor : (startColor == 'W' ? 'B' : 'W');
            if(board[startX + i][startY +j] != color)
            {
                wrongcount++;
            }
        }
    }

    return wrongcount;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("chess.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> board(N, vector<char>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int startX = N - 7;
    int startY = M - 7;

    int mincount = 64;

    for(int i = 0; i < startX; i++)
    {
        for(int j = 0; j < startY; j++)
        {
            int wcount = getwrongcount(board, i, j, 'W');
            int bcount = getwrongcount(board, i, j, 'B');

            mincount = min({wcount, bcount, mincount});

        }
    }

    cout << mincount << endl;
    
    return 0;
}