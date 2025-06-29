#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("zero.txt", "r", stdin);

    int K;

    cin >> K;

    stack<int> st;

    for(int i = 0; i < K; i++)
    {
        int n;
        cin >> n;

        if(n == 0)
        {
            st.pop();
        }
        else
        {
            st.push(n);
        }
    }

    if(st.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        int sum = 0;
        while(!st.empty())
        {
            int n = st.top();
            sum += n;
            st.pop();
        }

        cout << sum << endl;
    }

    return 0;
}