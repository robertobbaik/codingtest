#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int> &arr, int depth, int N, int M)
{
    if(depth == M)
    {
        for(int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        arr[depth] = i;
        backtracking(arr, depth + 1, N, M); 
    }
}

int main(void)
{
    freopen("NM1.txt", "r", stdin);

    int N, M;

    cin >> N >> M;

    vector<int> arr(N + 1);
    backtracking(arr, 0, N, M);

    return 0;
}