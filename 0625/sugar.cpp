#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    queue<pair<int, int>> q;

    q.push({0, 0});

    int count = -1;
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();

        if (a == N)
        {
            count = b;
            break;
        }

        if (a + 3 <= N)
        {
            q.push({a + 3, b + 1});
            if (a + 5 <= N)
            {
                q.push({a + 5, b + 1});
            }
        }
    }

    cout << count << endl;

    return 0;
}