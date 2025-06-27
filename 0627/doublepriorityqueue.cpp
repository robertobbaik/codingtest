#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("doublepriorityqueue.txt", "r", stdin);

    int T;

    cin >> T;

    while (T--)
    {
        int k;
        cin >> k;

        multiset<int> pq;
        for (int i = 0; i < k; i++)
        {
            char c;
            cin >> c;
            int n;
            cin >> n;

            if (c == 'I')
            {
                pq.insert(n);
            }
            else
            {
                if (!pq.empty())
                {
                    if (n == 1)
                    {
                        pq.erase(prev(pq.end()));
                    }
                    else
                    {
                        pq.erase(pq.begin());
                    }
                }
            }
        }

        if (pq.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << *pq.rbegin() << " " << *pq.begin() << "\n";
        }
    }

    return 0;
}