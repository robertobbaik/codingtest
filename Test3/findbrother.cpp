#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    freopen("findbrother.txt", "r", stdin);

    int N, K;

    cin >> N >> K;

    queue<pair<int, int>> q;
    vector<bool> visited(100001, false);

    int time = 0;
    q.push({N, time});
    visited[N] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();
        // cout << x << " " << time << endl;

        if (x == K)
        {
            cout << time << endl;
            break;
        }

        if (x + 1 >= 0 && x + 1 < 100001 && !visited[x + 1])
        {
            visited[x + 1] = true;
            q.push({x + 1, time + 1});
            
        }

        if (x - 1 >= 0 && !visited[x - 1] && x - 1 < 100001)
        {
            visited[x - 1] = true;
            q.push({x - 1, time + 1});
            //
        }

        if (2 * x >= 0 && 2 * x < 100001 && !visited[2 * x])
        {
            visited[2 * x] = true;
            q.push({2 * x, time + 1});
            //
        }
    }

    return 0;
}