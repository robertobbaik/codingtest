#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<char>> board;

int getwrongcount(int startN, int startM, char startColor)
{
    int wrong_count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char expectedColor = ((i + j) % 2 == 0) ? startColor : (startColor == 'W' ? 'B' : 'W');
            if (board[startN + i][startM + j] != expectedColor)
            {
                wrong_count++;
            }
        }
    }
    return wrong_count;
}

int main(void)
{
    freopen("chess.txt", "r", stdin);

    cin >> N >> M;

    board.resize(N, vector<char>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int splitN = N - 8;
    int splitM = M - 8;

    // 15 16 17 18 19 20 21 22 23
    
    int min_count = 64;
    for (int i = 0; i <= splitN; i++)
    {
        for (int j = 0; j <= splitM; j++)
        {
            int wcount = getwrongcount(i, j, 'W');
            int bcount = getwrongcount(i, j, 'B');
            
            min_count = min({min_count, wcount, bcount});
        }
    }
    cout << min_count << endl;

    return 0;
}