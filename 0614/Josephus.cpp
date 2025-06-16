#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void)
{
    freopen("Josephus.txt", "r", stdin);
    int N, K;

    cin >> N >> K;

    deque<int> dq;

    for (int i = 0; i < N; i++)
    {
        dq.push_back(i + 1);
    }

    int temp = 0;
    cout << "<";

    while (!dq.empty())
    {
        temp++;
        int num = dq[0];
        dq.pop_front();

        if (temp == K)
        {
            temp = 0;
            if (dq.empty())
            {
                cout << num << ">" << endl;
            }
            else
            {
                cout << num << ", ";
            }
        }
        else
        {
            dq.push_back(num);
        }
    }

    return 0;
}