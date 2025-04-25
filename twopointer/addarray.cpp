#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("addarray.txt", "r", stdin);

    int T;

    cin >> T;

    int n;

    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int m;
    cin >> m;
    vector<int> B(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }

    vector<long long> sumA;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            sumA.push_back(sum);
        }
    }

    vector<long long> sumB;

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = i; j < m; j++)
        {
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    sort(sumB.begin(), sumB.end());

    long long count = 0;

    for (int n : sumA)
    {
        int target = T - n;
        auto range = equal_range(sumB.begin(), sumB.end(), target);
        count += distance(range.first, range.second);
    }

    cout << count << endl;

    return 0;
}