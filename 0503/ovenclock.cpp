#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    freopen("ovenclock.txt", "r", stdin);

    int A, B, C;

    cin >> A >> B >> C;

    int time = (B + C) / 60;

    int minute = (B + C) % 60;

    A = (A + time) % 24;
    
    cout << A << " " << minute << endl;

    return 0;
}