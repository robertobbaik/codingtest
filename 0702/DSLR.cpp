#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int D(int n)
{
    return n * 2 % 10000;
}

int S(int n)
{
    if (n - 1 == 0)
    {
        return 9999;
    }

    return n - 1;
}

int L(int n)
{
    string str = to_string(n);
    rotate(str.begin(), str.begin() + 1, str.end());

    return stoi(str);
}

int R(int n)
{
    string str = to_string(n);
    rotate(str.rbegin(), str.rbegin() + 1, str.rend());

    return stoi(str);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("DSLR.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        int A, B;
        cin >> A >> B;
        queue<pair<int, string>> q;
        vector<bool> visited(10000, false);
        q.push({A, ""});

        while (!q.empty())
        {
            auto [n, commands] = q.front();
            q.pop();

            if (n == B)
            {
                cout << commands << endl;
                break;
            }

            int operations[4] = {D(n), S(n), L(n), R(n)};
            char ops[4] = {'D', 'S', 'L', 'R'};

            for (int i = 0; i < 4; i++)
            {
                if (!visited[operations[i]])
                {
                    visited[operations[i]] = true;
                    q.push({operations[i], commands + ops[i]});
                }
            }
        }
    }

    return 0;
}