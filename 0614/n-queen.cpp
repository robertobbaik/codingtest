#include <iostream>
#include <vector>

using namespace std;

int N;
int answer = 0;
vector<int> col; // col[row] = 퀸이 놓인 열 번호

bool isValid(int row, int c)
{
    for (int i = 0; i < row; i++)
    {
        if (col[i] == c || abs(row - i) == abs(col[i] - c))
        {
            return false;
        }
    }
    return true;
}

void dfs(int row)
{
    if (row == N)
    {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (isValid(row, i))
        {
            col[row] = i;
            dfs(row + 1);
        }
    }
}

int main(void)
{
    cin >> N;
    col.resize(N);
    dfs(0);
    cout << answer << "\n";
    return 0;
}