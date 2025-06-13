#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtracking(vector<int> &arr, vector<bool> &used, int depth, int N, int M)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            arr[depth] = i;
            backtracking(arr, used, depth + 1, N, M);
            used[i] = false;
        }
    }
}

int main(void)
{
    freopen("NM1.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<int> arr(M);
    vector<bool> used(N + 1, false);

    backtracking(arr, used, 0, N, M);

    return 0;
}