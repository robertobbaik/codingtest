#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
    freopen("absheap.txt", "r", stdin);
    int N;

    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top().second << "\n";
                pq.pop();
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            pq.push({abs(n), n});
        }
    }

    return 0;
}