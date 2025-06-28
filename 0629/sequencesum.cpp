#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
int result = 0;

void backtracking(int sum, int index)
{
    if(index >= N) return;
    sum += arr[index];

    if (sum > M)
    {
        return;
    }
    else if (sum == M)
    {
        result++;
        return;
    }
    else if(sum < M)
    {
        backtracking(sum, index + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sequencesum.txt", "r", stdin);

    cin >> N >> M;

    arr.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        backtracking(0, i);
    }

    cout << result << endl;

    return 0;
}