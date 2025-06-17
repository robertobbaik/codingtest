#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    freopen("alarm.txt", "r", stdin);
    int H, M;
    cin >> H >> M;

    //10 10 
    // 9 25

    if(M < 45)
    {
        H--;
        if(H < 0)
        {
            H = 23;
        }
        M = M + 60 - 45;
    }
    else
    {
        M -= 45;
    }

   cout << H << " " << M << endl;

    return 0;
}