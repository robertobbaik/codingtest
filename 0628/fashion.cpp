#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("fashion.txt", "r", stdin);

    int T;

    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        unordered_map<string, int> um;

        for (int i = 0; i < n; i++)
        {
            string str1, str2;
            cin >> str1 >> str2;

            um[str2]++;
        }

        int count = 1;

        for (auto m : um)
        {
            count *= (m.second + 1);
        }

        count -= 1;
        cout << count << endl;
    }
    return 0;
}