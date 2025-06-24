#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("tree.txt", "r", stdin);

    int N, M;
    cin >> N >> M;
    vector<int> tree(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];
    }

    int left = 0;

    int right = *max_element(tree.begin(), tree.end());
    int answer = 0;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        long long remainder = 0;

        for(int i = 0; i < N; i++)
        {
            if(tree[i] > mid)
            {
                remainder += tree[i] - mid;
            }
        }

        if(remainder >= M)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}