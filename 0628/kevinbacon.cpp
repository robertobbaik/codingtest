#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <numeric>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("kevinbacon.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> connection(N + 1);
    vector<vector<int>> count(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        connection[A].push_back(B);
        connection[B].push_back(A);
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (i == j)
                continue;
            queue<tuple<int, int, int>> q;
            vector<bool> visited(N + 1, false);

            q.push({j, 0, i});
            visited[i] = true;

            while (!q.empty())
            {
                auto [target, depth, next] = q.front();
                q.pop();

                if (target == next)
                {
                    count[i][target] = depth;
                    break;
                }

                for (int k = 0; k < connection[next].size(); k++)
                {
                    if (!visited[connection[next][k]])
                    {
                        q.push({target, depth + 1, connection[next][k]});
                        visited[connection[next][k]] = true;
                    }
                }
            }
        }
    }

    vector<int> result;

    for (int i = 1; i < N + 1; i++)
    {
        int sum = accumulate(count[i].begin(), count[i].end(), 0);
        result.push_back(sum);
    }

    int min = *min_element(result.begin(), result.end());

    for(int i = 0; i < N; i++)
    {
        if(result[i] == min)
        {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}