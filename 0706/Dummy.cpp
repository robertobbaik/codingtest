#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("Dummy.txt", "r", stdin);

    int N, K;

    cin >> N >> K;

    vector<pair<int, int>> apple(K);

    set<pair<int, int>> apples;

    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        apples.insert({x - 1, y - 1});
    }

    int L;
    cin >> L;

    unordered_map<int, char> um;

    for (int i = 0; i < L; i++)
    {
        int second;
        char rot;

        cin >> second;
        cin >> rot;

        um[second] = rot;
    }

    int time = 0;
    int direction = 0;

    deque<pair<int, int>> length;
    length.push_back({0, 0});
    while (true)
    {
        time++;
        auto [x, y] = length[0];

        if (direction == 0)
        {
            y++;
        }
        else if (direction == 1)
        {
            x++;
        }
        else if (direction == 2)
        {
            y--;
        }
        else if (direction == 3)
        {
            x--;
        }

        if (x < 0 || x >= N || y < 0 || y >= N)
        {
            break;
        }

        for (auto &[bx, by] : length)
        {
            if (bx == x && by == y)
            {
                cout << time << endl;
                return 0;
            }
        }

        length.push_front({x, y});

        if (apples.count({x, y}))
        {
            apples.erase({x, y});
        }
        else
        {
            length.pop_back();
        }

        if (um.count(time))
        {
            char rot = um[time];

            if (rot == 'D')
            {
                direction = (direction + 1) % 4;
            }
            else
            {
                direction = (direction + 3) % 4;
            }
        }
    }
    cout << time << endl;

    return 0;
}