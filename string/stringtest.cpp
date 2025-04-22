#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
    string input = "1 2 3 4 5";
    stringstream ss(input);
    string token;
    
    while(getline(ss, token, ' '))
    {
        cout << token << endl;
    }


}