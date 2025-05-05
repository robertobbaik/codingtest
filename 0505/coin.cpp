#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    freopen("coin.txt", "r", stdin);
    int N, K;

    cin >> N >> K;

    vector<int> coins(N);

    for(int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    int target = 0;
    int count = 0;
    while(target < K)
    {
        for(int i = N - 1; i >= 0; i--)
        {
            if(target + coins[i] <= K)
            {
                target += coins[i];
                count++;
                break;
            }
        }
    }
    cout << count << endl;

    return 0;
}