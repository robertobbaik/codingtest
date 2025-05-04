#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int N;

    cin >> N;

    int count = 1;
    int numbering = 666;

    while (count < N)
    {
        numbering++;

        if (to_string(numbering).find("666") != string::npos)
        {
            count++;
        }
    }

    cout << numbering << endl;
    return 0;
}