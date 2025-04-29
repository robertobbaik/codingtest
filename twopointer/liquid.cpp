#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("liquid.txt", "r", stdin);

    int N;

    cin >> N;

    vector<int> liquid(N);

    for (int i = 0; i < N; i++)
    {
        cin >> liquid[i];
    }

    sort(liquid.begin(), liquid.end());

    int left = 0;
    int right = N - 1;

    int best = INT_MAX;
    int result_left = 0, result_right = 0;

    while (left < right)
    {
        int l = liquid[left] + liquid[right];

        if (abs(l) < best)
        {
            best = abs(l);
            result_left = liquid[left];
            result_right = liquid[right];
        }

        if (l < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << result_left << " " << result_right << endl;

    return 0;
}