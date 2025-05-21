#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>> &board, vector<bool> &visited, int u)
{
    visited[u] = true;
    for (int i = 0; i < board[u].size(); i++)
    {
        if (!visited[board[u][i]])
        {
            dfs(board, visited, board[u][i]);
        }
    }
}

int main(void)
{
    freopen("connectcount.txt", "r", stdin);
    int N, M;

    cin >> N >> M;

    vector<vector<int>> board(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;

        cin >> u >> v;

        board[u].push_back(v);
        board[v].push_back(u);
    }

    int count = 0;
    vector<bool> visited(N + 1, false);

    for (int i = 1; i < board.size(); i++)
    {
        if (!visited[i])
        {
            dfs(board, visited, i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}