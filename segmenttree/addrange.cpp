#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    freopen("addrange.txt", "r", stdin);

    int N, M, K;

    cin >> N >> M >> K;

    vector<long long> sequence(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }

    vector<vector<long long>> commands;

    for (long long i = 0; i < M + K; i++)
    {
        vector<long long> command;

        for (int j = 0; j < 3; j++)
        {
            int temp;

            cin >> temp;
            command.push_back(temp);
        }

        commands.push_back(command);
    }

    for (long long i = 0; i < M + K; i++)
    {
        if (commands[i][0] == 1)
        {
            sequence[(commands[i][1] - 1)] = commands[i][2];

            // for(int n : sequence)
            // {
            //     cout << n << " ";
            // }
            // cout << endl;
        }
        else
        {
            long long sum = 0;
            long long start = commands[i][1] - 1;
            long long end = commands[i][2];
            for (long long i = start; i < end; i++)
            {
                sum += sequence[i];
            }

            cout << sum << endl;
        }
    }

    return 0;
}
