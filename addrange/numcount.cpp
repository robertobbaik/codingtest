#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main(void)
{
    freopen("numcount.txt", "r", stdin);
    ll temp = 1;

    vector<int> arr(10, 0);

    for(int i = 0; i < 3; i++)
    {
        ll num;

        cin >> num;

        temp *= num;
    }

    while(temp)
    {
        arr[temp % 10]++;
        temp /= 10;
    }

    for(int n : arr)
    {
        cout << n << endl;
    }

    return 0;
}