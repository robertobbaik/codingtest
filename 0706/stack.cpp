#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("stack.txt", "r", stdin);

    int n;

    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int index = 0;
    int currentNum = 1;
    stack<int> s;
    unordered_set<int> used;
    vector<char> symbol;
    while (index < n)
    {
        if (s.empty() || s.top() < arr[index])
        {
            if (currentNum > n)
            {
                cout << "NO" << endl;
                return 0;
            }

            s.push(currentNum);
            symbol.push_back('+');
            currentNum++;
        }
        else if (s.top() == arr[index])
        {
            s.pop();
            symbol.push_back('-');
            index++;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (char c : symbol)
    {
        cout << c << "\n";
    }

    return 0;
}