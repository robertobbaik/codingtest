#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
vector<int> arr;
int N, M, L;

bool canConstruct(int distance)
{
    int prev = 1;
    
    for (int i = 0; i < N; i++)
    {
        if (arr[i] - prev > distance)
        {

        }
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("restarea.txt", "r", stdin);

    cin >> N >> M >> L;
    arr.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 1;
    int right = 0;

    for (int i = 1; i < N; i++)
    {
        int dis = arr[i] - arr[i - 1];
        right += dis;
    }

    cout << right / M + N << endl;

    int answer = 0;

    //82 102 201 204 306 408 411 513 555 622 

    // while (left <= right)
    // {
    //     int mid = (left + right) / 2;
    // }

    return 0;
}