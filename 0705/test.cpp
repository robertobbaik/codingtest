#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *p = &x;
    int **pp = &p;

    cout << "1. x = " << x << endl;
    cout << "2. *p = " << *p << endl;
    cout << "3. **pp = " << **pp << endl;

    *p = 20;
    cout << "4. x = " << x << endl;

    int y = 30;
    *pp = &y;

    cout << "5. *p = " << *p << endl;
    cout << "6. **pp = " << **pp << endl;
    cout << "7. x = " << x << endl;

    **pp = 40;
    cout << "8. y = " << y << endl;
    cout << "9. x = " << x << endl;

    return 0;
}