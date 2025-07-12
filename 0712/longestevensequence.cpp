#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEven(int num)
{
    return num % 2 == 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("longestevensequence.txt", "r", stdin);
 
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int left = 0;
    int oddCount = 0;
    int max_len = 0;

    for(int right = 0; right < N; right++)
    {
        if(!isEven(arr[right]))
        {
            oddCount++;
        }

        
    }

    return 0;
}