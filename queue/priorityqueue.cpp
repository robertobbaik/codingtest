#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("priorityqueue.txt", "r", stdin);
    int casecount;

    cin >> casecount;

    for (int i = 0; i < casecount; i++)
    {
        int N, M;
        cin >> N >> M;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int i = 0; i < N; i++)
        {
            int importance;
            cin >> importance;

            q.push({i, importance});
            pq.push(importance);
        }

        int count = 0;

        while (!q.empty())
        {
            int idx = q.front().first;
            int imp = q.front().second;

            q.pop();

            if(imp == pq.top())
            {
                pq.pop();
                count++;

                if(idx == M)
                {
                    cout << count << "\n";
                    break;
                }
            }
            else
            {
                q.push({idx, imp});
            }
        }
    }

    return 0;
}