#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    string s = "dvca";

    sort(s.begin(), s.end());

    cout << s << endl;

    return 0;
}