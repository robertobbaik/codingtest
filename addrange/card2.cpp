#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    deque<int> d;

    for(int i = 1; i <= N; i++)
    {
        d.push_back(i);
    }

    while(d.size() > 1)
    {
        d.pop_front();

        int top = d.front();

        d.pop_front();
        d.push_back(top);
    }

    cout << d[0] << endl;

    return 0;
}