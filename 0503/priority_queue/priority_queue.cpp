#include <queue>
#include <iostream>

using namespace std;

int main(void)
{
    priority_queue<int> pq;

    pq.push(456);
    pq.push(123);
    pq.push(789);

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}