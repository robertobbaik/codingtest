#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    freopen("starttaxi.txt", "r", stdin);
    int N, M, fuel;

    cin >> N >> M >> fuel;

    vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            cin >> board[i][j];
        }
    }

    int col, row;

    cin >> col >> row;

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
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));

        queue<pair<pair<int, int>, int>> q;

        q.push({{col, row}, 0});
        visited[col][row] = true;
        bool isFind = true;
        int targetCol = 0;
        int targetRow = 0;

        int count = 0;

        while (!q.empty())
        {
            int col = q.front().first.first;
            int row = q.front().first.second;
            int depth = q.front().second;

            q.pop();
            for (int i = 0; i < M; i++)
            {
                if (isFind)
                {
                    if (col == move[i][0] && row == move[i][1])
                    {
                        fuel -= depth;
                        cout << move[i][0] << ", " << move[i][1] << endl;

                        while (!q.empty())
                        {
                            q.pop();
                        }
                        visited.assign(N + 1, vector<bool>(N + 1, false));
                        q.push({{move[i][0], move[i][1]}, 0});
                        targetCol = move[i][2];
                        targetRow = move[i][3];
                        visited[move[i][0]][move[i][1]] = true;

                        move.erase(move.begin() + i);

                        isFind = false;

                        break;
                    }
                }
                else
                {
                    if (col == targetCol && row == targetRow)
                    {
                        fuel -= depth;
                        fuel += depth * 2;
                        count++;
                        isFind = true;

                        while (!q.empty())
                        {
                            q.pop();
                        }

                        if (count == M)
                        {
                            cout << fuel << endl;
                        }
                        else
                        {
                            visited.assign(N + 1, vector<bool>(N + 1, false));
                            q.push({{targetCol, targetRow}, 0});
                        }
                    }
                }
            }

            if (fuel - depth <= 0)
            {
                cout << "Fuel empty" << endl;
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int ncol = col + dy[i];
                int nrow = row + dx[i];

                if (ncol > 0 && ncol <= N && nrow > 0 && nrow <= N)
                {
                    if (!visited[ncol][nrow] && board[ncol][nrow] == 0)
                    {
                        q.push({{ncol, nrow}, depth + 1});
                        visited[ncol][nrow] = true;
                    }
                }
            }
        }
    }
}