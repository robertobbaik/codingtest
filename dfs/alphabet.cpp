#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<int> result;
int max_count;
bool visited[26];

void dfs(const vector<string> &board, int x, int y, int n, int m, int count)
{
    max_count = max(max_count, count);

    char c = board[y][x];
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n)
        {
            int nc = board[ny][nx] - 'A';

            if(!visited[nc])
            {
                visited[nc] = true;
                dfs(board, nx, ny, n, m, count + 1);
                visited[nc] = false;
            }
            
        }
    }
}

int main(void)
{
    freopen("alphabet.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<string> board;

    for (int i = 0; i < N; i++)
    {
        string str;

        cin >> str;

        board.push_back(str);
    }

    char c = board[0][0];
    int idx = c - 'A';

    visited[idx] = true;
    dfs(board, 0, 0, N, M, 1);

    cout << max_count << endl;

    return 0;
}