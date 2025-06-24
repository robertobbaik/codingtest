#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits> 

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ATM.txt", "r", stdin);

    int N;
    cin >> N;

    vector<int> time(N);

    for (int i = 0; i < N; i++)
    {
        cin >> time[i];
    }

    sort(time.begin(), time.end());
    int t = INT_MAX;

    do
    {
        int sum = 0;
        vector<int> temp;

        for(int i = 0; i < N; i++)
        {
            sum += time[i];
            temp.push_back(sum);
        }

        t = min(accumulate(temp.begin(), temp.end(), 0), t);
    } while (prev_permutation(time.begin(), time.end()));

    cout << t << endl;

    return 0;
}