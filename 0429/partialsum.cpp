#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    freopen("partialsum.txt", "r", stdin);

    int N, S;

    cin >> N >> S;
    vector<int> sequence;
    for(int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        sequence.push_back(n);
    }

    sort(sequence.begin(), sequence.end());

    for(int n : sequence)
    {
        cout << n << " ";
    }

    return 0;
}