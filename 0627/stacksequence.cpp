#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("stacksequence.txt", "r", stdin);

    int n;

    cin >> n;
    int current = 1;
    stack<int> st;
    string result = "";

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        while (current <= v[i])
        {
            st.push(current);
            current++;

            result += "+\n";
        }

        if (st.top() == v[i])
        {
            st.pop();
            result += "-\n";
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << result;

    return 0;
}