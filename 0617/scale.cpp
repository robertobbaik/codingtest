#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    freopen("scale.txt", "r", stdin);
    vector<int> scale(8, 0);

    for(int i = 0; i < 8; i++)
    {
        cin >> scale[i];
    }

    vector<int> temp = scale;

    sort(temp.begin(), temp.end());

    if(temp == scale)
    {
        cout << "ascending" << endl;
    }
    else
    {
        sort(temp.begin(), temp.end(), greater<int>());

        if(temp == scale)
        {
            cout << "descending" << endl;
        }
        else
        {
            cout << "mixed" << endl;
        }
    }

    return 0;
}