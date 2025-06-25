#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isValid(int n)
{
    if(n < 100) return true;
    if(n == 1000) return false;

    vector<int> arr;

    while(n)
    {
        int temp = n % 10;
        arr.push_back(temp);
        n /= 10; 
    }

    return (arr[0] - arr[1]) == (arr[1] - arr[2]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //freopen("num.txt", "r", stdin);

    int N;
    cin >> N;


    int result = 0;

    for(int i = 1; i <= N; i++)
    {
        if(isValid(i))
        {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}