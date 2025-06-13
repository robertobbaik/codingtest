#include <iostream>
#include <vector>

using namespace std;

void backtracing(vector<int> &arr, int depth, int start, int N, int M)
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

    for (int i = start; i <= N; i++)
    {
        arr[depth] = i;
        backtracing(arr, depth + 1, i, N, M);
    }
}

int main(void)
{
    freopen("NM1.txt", "r", stdin);
    int N, M;

    cin >> N >> M;

    vector<int> arr(N + 1);
    backtracing(arr, 0, 1, N, M);
    return 0;
}