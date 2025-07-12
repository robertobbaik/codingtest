#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("uniquenum.txt", "r", stdin);

    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    unordered_set<int> window;
    long long count = 0;
    int left = 0;

    for(int right = 0; right < N; right++)
    {
        while(window.count(arr[right]))
        {
            window.erase(arr[left]);
            left++;
        }

        window.insert(arr[right]);

        count += (right - left + 1);
    }

    cout << count << endl;

    return 0;
}