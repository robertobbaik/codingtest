#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    freopen("addrange.txt", "r", stdin);

    int M, N;

    cin >> M >> N;

    vector<int> v(M + 1, 0);
    vector<int> prefix(M + 1, 0);

    for (int i = 1; i <= M; i++)
    {
        cin >> v[i];
        prefix[i] = prefix[i - 1] + v[i];
    }

    vector<pair<int, int>> commands(N);

    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;

        cout << prefix[end] - prefix[start - 1] << endl;
    }

    return 0;
}