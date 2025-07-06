#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool broken[10];

bool canMake(int channel)
{
    if (channel == 0)
    {
        return !broken[0];
    }

    while (channel)
    {
        int digit = channel % 10;
        if (broken[digit])
        {
            return false;
        }

        channel /= 10;
    }

    return true;
}

int getLength(int channel)
{
    if (channel == 0)
        return 1;
    int length = 0;
    while (channel)
    {
        length++;
        channel /= 10;
    }

    return length;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("remotecontroller.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        broken[n] = true;
    }

    int minPress = abs(N - 100);

    for (int i = 0; i <= 999999; i++)
    {
        if (canMake(i))
        {
            int press = getLength(i) + abs(N - i);
            minPress = min(minPress, press);
        }
    }

    cout << minPress << endl;

    return 0;
}