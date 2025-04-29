#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("Aggressivecows.txt", "r", stdin);

    int N, C;

    cin >> N >> C;

    vector<int> x(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    int left = 1;
    int right = x[N - 1] - x[0];
    int result = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        int c = 1;
        int last = x[0];

        for (int i = 1; i < N; i++)
        {
            if (x[i] - last >= mid)
            {
                c++;
                last = x[i];
            }
        }

        if (c >= C)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}
