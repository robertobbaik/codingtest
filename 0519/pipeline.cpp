#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("pipeline.txt", "r", stdin);

    int N, L;

    cin >> N >> L;

    vector<int> points(N);

    for (int i = 0; i < N; i++)
    {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int tapecount = 0;
    double end = 0.0f;

    for (int i = 0; i < N; i++)
    {
        if(points[i] > end)
        {
            tapecount++;
            end = points[i] - 0.5f + L;
        }
    }

    cout << tapecount << endl;

    return 0;
}