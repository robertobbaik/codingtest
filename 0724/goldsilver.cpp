#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{

    int n = g.size();

    long long left = 0, right = 4e15;
    long long answer = right;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long totalGold = 0, totalSilver = 0, totalBoth = 0;

        for (int i = 0; i < n; i++)
        {
            long long trips = mid / (2LL * t[i]);
            if (mid % (2LL * t[i]) >= t[i])
            {
                trips++;
            }

            long long maxTransport = trips * w[i];

            long long gold = min((long long)g[i], maxTransport);
            long long silver = min((long long)s[i], maxTransport);
            long long both = min((long long)(g[i] + s[i]), maxTransport);

            totalGold += gold;
            totalSilver += silver;
            totalBoth += both;
        }

        if (totalGold >= a && totalSilver >= b && totalBoth >= a + b)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}

int main(void)
{
    long long result = solution(90, 500, {70, 70, 0}, {0, 0, 500}, {100, 100, 2}, {4, 8, 1});
    cout << result << endl;
    return 0;
}