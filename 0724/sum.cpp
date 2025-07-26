#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("sum.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int left = 0;
    int sum = 0;
    int answer = 0;
    
    for(int right = 0; right < N; right++)
    {
        sum += arr[right];

        while(sum > M && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        if(sum == M)
        {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}