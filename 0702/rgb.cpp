#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("rgb.txt", "r", stdin);

    int N;

    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j]; 
        }
    }

    
    return 0;
}