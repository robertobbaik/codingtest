#include <iostream>
#include <vector>

using namespace std;
int N, S;

int result = 0;
vector<int> arr;
void backtracking(int sum, int index)
{
    if (sum == S)
    {
        result++;
        return;
    }

    if (index >= N)
    {
        return;
    }

    sum += arr[index];
    backtracking(sum, index + 1);
    sum -= arr[index];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sequence.txt", "r", stdin);

    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    backtracking(0, 0);

    cout << result << endl;

    return 0;
}