#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    //freopen("phonenum.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        string answer = "YES";
        vector<string> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1].size() > nums[i].size() && nums[i + 1].substr(0, nums[i].size()) == nums[i])
            {
                answer = "NO";
                break;
            }
        }

        cout << answer << endl;
    }

    return 0;
}