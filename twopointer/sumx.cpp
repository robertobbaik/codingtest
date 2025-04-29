#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("sumx.txt", "r", stdin);

    int n;

    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x;

    cin >> x;

    sort(a.begin(), a.end());
    int left = 0;
    int right = n - 1;

    int result = 0;

    while(left < right)
    {
        int sum = a[left] + a[right];

        if(sum > x)
        {
            right--;
        }
        else if(sum < x)
        {
            left++;
        }
        else
        {
            left++;
            right--;
            result++;
        }
    }

    cout << result << endl;

    return 0;
}