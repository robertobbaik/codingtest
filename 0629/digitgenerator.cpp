#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("digitgenerator.txt", "r", stdin);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        int temp = i;
        int sum = 0;

        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }

        if (i + sum == N)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}