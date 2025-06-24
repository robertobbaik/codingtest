#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("coin.txt", "r", stdin);

    int N, K;

    cin >> N >> K;

    vector<int> coins(N);

    for(int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    int count = 0;
    int target = 0;

    while(target < K)
    {
        for(int i = 0; i < N; i++)
        {
            if(K - target >= coins[N - 1 - i])
            {
                count++;
                target += coins[N - 1 - i];
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}