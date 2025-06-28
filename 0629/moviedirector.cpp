#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("moviedirector.txt", "r", stdin);

    int N; 
    cin >> N;

    int count = 1;
    int start = 666;
    while(count < N)
    {
        start++;
        if(to_string(start).find("666") != string::npos)
        {
            count++;
        }
    }

    cout << start << endl;

    return 0;
}