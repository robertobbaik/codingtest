#include <iostream>
#include <vector>

using namespace std;

bool can_cut(const vector<int> &woods, int len, int target)
{
    int remainder = 0;
    for (int i = 0; i < woods.size(); i++)
    {
        if (woods[i] >= len)
        {
            remainder += woods[i] - len;
        }
    }

    return remainder >= target;
}

int main(void)
{
    freopen("wood.txt", "r", stdin);
    int N;
    cin >> N;

    int need;
    cin >> need;

    vector<int> woods(N);

    for (int i = 0; i < N; i++)
    {
        cin >> woods[i];
    }

    int left = 1;
    int right = *max_element(woods.begin(), woods.end());
    int answer = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (can_cut(woods, mid, need))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}