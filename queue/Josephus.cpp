#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main(void)
{
    freopen("Josephus.txt", "r", stdin);

    int N, K;

    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }
    cout << "<";
    int num = 0;

    while (!q.empty())
    {
        int n = q.front();
        num++;
        q.pop();

        if (num == K)
        {
            cout << n;
            if (!q.empty())
            {
                cout << ", ";
            }
            num = 0;
        }
        else
        {
            q.push(n);
        }
    }

    cout << ">" << endl;

    return 0;
}