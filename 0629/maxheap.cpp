#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("maxheap.txt", "r", stdin);

    priority_queue<int> q;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if(num == 0)
        {
            if(!q.empty())
            {
                cout << q.top() << "\n";
                q.pop();
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            q.push(num);
        }
    }

    return 0;
}