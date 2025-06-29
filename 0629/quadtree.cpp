#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;

void compression(int len, int x, int y)
{
    int start = board[x][y];
    bool isSame = true;
    if(len == 1)
    {
        cout << start;
        return;
    }

    for(int i = x; i < x + len; i++)
    {
        for(int j = y; j < y + len; j++)
        {
            if(board[i][j] != start)
            {
                isSame = false;
                break;
            }
        }
        if(!isSame)
        {
            break;
        }
    }

    if(isSame)
    {   
        cout << start;
    }
    else
    {
        int half = len / 2;
        cout << "(";
        compression(half, x, y);
        compression(half, x, y + half);
        compression(half, x + half, y);
        compression(half, x + half, y + half);
        cout << ")";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("quadtree.txt", "r", stdin);

    int N;

    cin >> N;

    board.resize(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < N; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }

    compression(N, 0, 0);
    return 0;
}