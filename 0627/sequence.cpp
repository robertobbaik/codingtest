#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sequence.txt", "r", stdin);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < M + K; i++)
    { 
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1)
        {
            v[b - 1] = c;
        }
        else
        {
            long long sum = 0;
            for(int i = b - 1; i <= c - 1; i++)
            {
                sum += v[i];
            }
            cout << sum << "\n";
        }
    }

    return 0;
}