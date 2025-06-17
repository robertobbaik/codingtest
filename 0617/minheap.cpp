#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("minheap.txt", "r", stdin);
    priority_queue<int, vector<int>, greater<int>> pq;

    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if(num == 0)
        {
            if(pq.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }

    return 0;
}