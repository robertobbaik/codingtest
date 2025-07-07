#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("rope.txt", "r", stdin);

    int N;

    cin >> N;

    vector<int> rope(N);

    for(int i = 0; i < N; i++)
    {
        cin >> rope[i];
    }

    sort(rope.begin(), rope.end(), greater<int>());

    int max_weight = 0;
    for(int i = 0; i < N; i++)
    {
        max_weight = max(max_weight, rope[i] * (i + 1));
    }

    cout << max_weight << endl;
    
    return 0;
}