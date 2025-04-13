#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main(void)
{
    freopen("train.txt", "r", stdin);

    int train_count, commands;
    cin >> train_count >> commands;

    vector<int> trains(train_count, 0);

    for (int i = 0; i < commands; i++)
    {
        int command_num;
        cin >> command_num;
        int train_num;
        int seat_num;
        switch (command_num)
        {
        case 1:
            cin >> train_num;
            cin >> seat_num;
            if ((trains[train_num - 1] & (1 << (seat_num - 1))) == 0)
            {
                //cout << (1 << (seat_num - 1)) << endl;
                trains[train_num - 1] += (1 << (seat_num - 1));
            }
            break;
        case 2:
            cin >> train_num;
            cin >> seat_num;
            if ((trains[train_num - 1] & (1 << (seat_num - 1))))
            {
                trains[train_num - 1] -= (1 << (seat_num - 1));
            }
            break;
        case 3:
            cin >> train_num;
            trains[train_num - 1] = (trains[train_num - 1] << 1) & ((1 << 20) - 1);
            break;
        case 4:
            cin >> train_num;
            trains[train_num - 1] >>= 1;
            break;
        }
    }

    unordered_set<int> si;

    for(int n : trains)
    {
        si.insert(n);
    }

    cout << si.size() << endl;

    return 0;
}