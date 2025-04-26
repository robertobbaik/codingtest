#include <iostream>
#include <unordered_set>

using namespace std;

int main(void)
{
    freopen("remaindercount.txt", "r", stdin);

    unordered_set<int> us;
    
    for(int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        int remainder = n % 42;
        us.insert(remainder);
    }

    //cout << endl;

    cout << us.size() << endl;

    return 0;
}