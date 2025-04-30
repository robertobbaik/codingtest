#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;

    cin >> N;

    int count = 0;
    while (N > 1)
    {
        count++;

        if (N % 3 == 0)
        {
            N /= 3;
            continue;
        }

        if (N % 2 == 0)
        {
            N /= 2;
            continue;
        }

        if (N - 1 > 0)
        {
            N -= 1;
            continue;
        }
    }

    cout << count << endl;

    return 0;
}