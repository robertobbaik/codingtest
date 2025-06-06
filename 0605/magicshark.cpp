#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, 1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(void)
{
    int N, M, K;

    cin >> N >> M >> K;

    vector<vector<int>> fireballinfo(M, vector<int>(5, 0));
    // r c m s d
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> fireballinfo[i][j];
        }
    }

    vector<vector<int>> board(N, vector<int>(N, 0));

    return 0;
}

// - f f -
// - - - -
// - - - -
// - - - -