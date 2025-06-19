#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("AB.txt", "r", stdin);

    long long A, B;

    cin >> A >> B;

    queue<pair<long long, int>> q;
    vector<bool> visited(B + 1, false);
    q.push({A, 1});
    visited[A] = true;

    while(!q.empty())
    {
        auto[num, depth] = q.front();
        q.pop();

        if(num == B)
        {
            cout << depth << endl;
            return 0;
        }

        long long a = num * 2;
        long long b = num * 10 + 1;

        if(a <= B && !visited[a])
        {
            q.push({a, depth + 1});
        }

        if(b <= B && !visited[b])
        {
            q.push({b, depth + 1});
        }
    }

    cout << -1 << endl;

    return 0;
}