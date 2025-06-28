#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>

using namespace std;

void rotate(deque<int> &cogwheel, int direction)
{
    if (direction == 1)
    {
        int n = cogwheel[7];
        cogwheel.pop_back();
        cogwheel.push_front(n);
    }
    else
    {
        int n = cogwheel[0];
        cogwheel.pop_front();
        cogwheel.push_back(n);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cogwheel.txt", "r", stdin);

    vector<deque<int>> cogwheel(4, deque<int>(8, 0));

    for (int i = 0; i < 4; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < 8; j++)
        {
            cogwheel[i][j] = str[j] - '0';
        }
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int num, direction;
        cin >> num >> direction;
        num--;
        vector<int> rotation(4, 0);
        rotation[num] = direction;

        for (int i = num; i > 0; i--)
        {
            if (cogwheel[i][6] != cogwheel[i - 1][2])
            {
                rotation[i - 1] = -rotation[i];
            }
            else
            {
                break;
            }
        }

        for (int i = num; i < 3; i++)
        {
            if (cogwheel[i][2] != cogwheel[i + 1][6])
            {
                rotation[i + 1] = -rotation[i];
            }
            else
            {
                break;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (rotation[i] != 0)
            {
                rotate(cogwheel[i], rotation[i]);
            }
        }
    }

    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        if (cogwheel[i][0] == 1)
        {
            score += pow(2, i);
        }
    }

    cout << score << endl;

    return 0;
}