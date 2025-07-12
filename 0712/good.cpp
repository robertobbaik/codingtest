#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("good.txt", "r", stdin);

    int N;
    cin >> N;

    vector<int> good(N);
    for (int i = 0; i < N; i++)
    {
        cin >> good[i];
    }

    sort(good.begin(), good.end());

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N - 1;

        while (left < right)
        {
            if (left == i)
            {
                left++;
                continue;
            }

            if (right == i)
            {
                right--;
                continue;
            }

            if (good[left] + good[right] == good[i])
            {
                count++;
                break;
            }
            else if (good[left] + good[right] > good[i])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
