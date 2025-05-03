#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool cancut(const vector<int> &lines, int length, int targetcount)
{
    int linecount = 0;
    for (int i = 0; i < lines.size(); i++)
    {
        int count = lines[i] / length;
        linecount += count;
    }

    return linecount >= targetcount;
}

int main(void)
{
    freopen("lanline.txt", "r", stdin);

    int K, N;

    cin >> K >> N;

    vector<int> lines(K);

    for (int i = 0; i < K; i++)
    {
        cin >> lines[i];
        cout << lines[i] << endl;
    }

    int left = 1;
    int right = *max_element(lines.begin(), lines.end());
    int answer = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (cancut(lines, mid, N))
        {
            left = mid + 1;
            answer = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}