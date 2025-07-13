#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("DNAPassword.txt", "r", stdin);
    
    int S, P;
    cin >> S >> P;

    string DNA;
    cin >> DNA;

    vector<int> ACGT(4);

    for(int i = 0; i < 4; i++)
    {
        cin >> ACGT[i];
    }

    
 
    return 0;
}