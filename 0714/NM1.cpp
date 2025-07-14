#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<bool> used;

void backtracking(int depth)
{
    if(depth == M)
    {
        for(int n : arr)
        {
            cout << n << " ";
        }
        cout << endl;

        return;
    }

    for(int i = 1; i <= N; i++)
    {
        if(!used[i])
        {
            used[i] = true;
            arr[depth] = i;
            backtracking(depth + 1);
            used[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    arr.resize(M);
    used.resize(N + 1, false);

    backtracking(0);

    return 0;
}