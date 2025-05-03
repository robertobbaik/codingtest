#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("printmax.txt", "r", stdin);

    vector<int> sequence;

    for (int i = 0; i < 9; i++)
    {
        int n;
        cin >> n;

        sequence.push_back(n);
    }

    int max = *max_element(sequence.begin(), sequence.end());

    auto it = find(sequence.begin(), sequence.end(), max);

    int dis = distance(sequence.begin(), it);

    cout << max << "\n"
         << dis + 1 << endl;

    return 0;
}