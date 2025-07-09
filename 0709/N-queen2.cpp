#include <iostream>
#include <vector>

using namespace std;

int N, total;
int col[15];

bool isValid(int level)
{
    for (int i = 0; i < level; i++)
    {
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
        {
            return false;
        }
    }

    return true;
}

void nqueen(int x)
{
    if (x == N)
    {
        total++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        col[x] = i;
        if(isValid(x))
        {
            nqueen(x + 1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("N-queen2.txt", "r", stdin);

    cin >> N;
    nqueen(0);
    cout << total << endl;
    return 0;
}