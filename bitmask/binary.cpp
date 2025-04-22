#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    freopen("binary.txt", "r", stdin);

    string A, B;

    cin >> A >> B;

    int len = A.size();

    for(int i = 0; i < len; i++)
    {
        if(A[i] == '1' && B[i] == '1')
        {
            cout << '1';
        }
        else
        {
            cout << '0';
        }
    }

    cout << endl;

    for(int i = 0; i < len; i++)
    {
        if(A[i] == '1' || B[i] == '1')
        {
            cout << '1'; 
        }
        else
        {
            cout << '0';
        }
    }

    cout << endl;

    for(int i = 0; i < len; i++)
    {
        if(A[i] == B[i])
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
    }

    cout << endl;

    for(int i = 0; i < len; i++)
    {
        if(A[i] == '1')
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
    }

    cout << endl;

    
    for(int i = 0; i < len; i++)
    {
        if(B[i] == '1')
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
    }



    return 0;
}