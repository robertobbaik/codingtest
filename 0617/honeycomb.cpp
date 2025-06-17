#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int weight = 1;
    int layer = 1;
    while(weight <= N)
    {
        weight += layer * 6;

        layer++;
    }

    cout << layer << endl;

    return 0;
}