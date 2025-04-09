#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    freopen("wallpaper.txt", "r", stdin);

    int T;
    cin >> T;

    vector<vector<int>> MNxy(T, vector<int>(4, 0));
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int n;

            cin >> n;
            MNxy[i][j] = n;
        }
    }

    for (int i = 0; i < T; i++)
    {
        int x = MNxy[i][2];
        int y = MNxy[i][3];

        int max_year = lcm(MNxy[i][0], MNxy[i][1]);

        while (true)
        {
            if (x > y)
            {
                y += MNxy[i][1];
            }
            else if (x < y)
            {
                x += MNxy[i][0];
            }

            if (x == y)
            {
                cout << x << endl;
                break;
            }

            if (x > max_year && y > max_year)
            {
                cout << -1 << endl;
                break;
            }
        }
    }

    return 0;
}