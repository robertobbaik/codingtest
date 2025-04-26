#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
    freopen("average.txt", "r", stdin);
    int N;

    cin >> N;

    vector<int> results(N, 0);

    for(int i = 0; i < N; i++)
    {
        cin >> results[i];
    }

    int M = *max_element(results.begin(), results.end());
    vector<float> average;
    for(int i = 0; i < N; i++)
    {
        float temp = (float)results[i] / (float)M;
        average.push_back(temp);
    }
    

    float sum = accumulate(average.begin(), average.end(), 0.0f);

    sum /= N;

    cout << sum * 100.0f << endl;

    return 0;
}