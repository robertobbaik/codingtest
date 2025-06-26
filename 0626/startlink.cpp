#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int getteamscore(const vector<vector<int>> &board, const vector<int> &arr)
{
    int teamscore = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (i == j)
            {
                continue;
            }

            teamscore += board[arr[i]][arr[j]];
        }
    }

    return teamscore;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("startlink.txt", "r", stdin);

    int N;
    cin >> N;

    vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<bool> select(N, false);
    for (int i = 0; i < N / 2; i++)
    {
        select[i] = true;
    }

    int result = INT_MAX;
    do
    {
        vector<int> team1, team2;

        for (int i = 0; i < N; i++)
        {
            if (select[i])
                team1.push_back(i + 1);
            else
                team2.push_back(i + 1);
        }

        int teamS = getteamscore(board, team1);
        int teamN = getteamscore(board, team2);

        result = min(result, abs(teamS - teamN));

    } while (prev_permutation(select.begin(), select.end()));
    cout << result << endl;

    return 0;
}