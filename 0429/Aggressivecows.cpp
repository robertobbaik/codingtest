#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(void)
{
    freopen("Aggressivecows.txt", "r", stdin);

    int N, C;

    cin >> N >> C;

    vector<int> x(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }



    return 0;
}
