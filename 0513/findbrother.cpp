#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void)
{
    freopen("findbrother.txt", "r", stdin);
    int N, K;

    cin >> N >> K;

    deque<pair<int, int>> q;
    vector<bool> visited(100001, false);
    q.push_back({N, 0});

    while (!q.empty())
    {
        auto [current_pos, time] = q.front();
        q.pop_front();

        if (visited[current_pos])
        {
            continue;
        }

        visited[current_pos] = true;

        if (current_pos == K)
        {
            cout << time << endl;
            return 0;
        }

        if (current_pos * 2 < 100001)
        {
            q.push_front({current_pos * 2, time});
        }

        if (current_pos + 1 < 100001)
        {
            q.push_back({current_pos + 1, time + 1});
        }

        if (current_pos - 1 >= 0)
        {
            q.push_back({current_pos - 1, time + 1});
        }
    }

    return 0;
}