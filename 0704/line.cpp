#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int greatestIndex(const deque<pair<int, int>> &lines, int N)
{
    vector<int> cross(N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            if (crossCheck(lines[i], lines[j]))
            {
                cross[i]++;
            }
        }
    }
    int index = -1;
    int maxVal = *max_element(cross.begin(), cross.end());
    if(maxVal == 0)
    {
        return -1;
    }

    for(int i = 0; i < N; i++)
    {
        if(maxVal == cross[i])
        {
            index = i;
            break;
        }
    }

    return index;
}

bool is_Finish(const deque<pair<int, int>> &lines, int N)
{
    vector<int> cross(N);
    bool isFinish = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            if (crossCheck(lines[i], lines[j]))
            {
                cross[i]++;
            }
        }
    }

    for (int n : cross)
    {
        if (n > 0)
        {
            isFinish = false;
            break;
        }
    }

    return isFinish;
}

bool crossCheck(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first < b.first && a.second > b.second)
    {
        return true;
    }

    if (a.first > b.first && a.second < b.second)
    {
        return true;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("line.txt", "r", stdin);

    int N;
    cin >> N;
    deque<pair<int, int>> lines(N);
    vector<int> crossed(N, 0);

    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;

        lines[i] = {A, B};
    }

    while (!is_Finish(lines, N))
    {
    }


    return 0;
}