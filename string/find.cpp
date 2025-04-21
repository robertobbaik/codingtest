#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    int blankcount = 0;
    int numcount = 0;
    int lowercount = 0;
    int uppercount = 0;
    int etc = 0;

    string str = "Hello world 123!";

    for(char c : str)
    {
        if(isalpha(c))
        {
            if(islower(c)) lowercount++;
            if(isupper(c)) uppercount++;
        }
        else
        {
            if(isblank(c)) blankcount++;
            else if(isnumber(c)) numcount++;
            else etc++;
        }
    }

    cout << blankcount << numcount << lowercount << uppercount << etc << endl;

    return 0;
}