#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int left = 0;
	int min_len = N + 1;
	int sum = 0;

	for (int right = 0; right < N; right++)
	{
		sum += arr[right];
		
		while(sum >= M)
		{
			min_len = min(min_len, right - left + 1);
			sum -= arr[left];
			left++;
		}
	}

    if (min_len == N + 1)
        cout << 0 << endl;
    else
        cout << min_len << endl;

	return 0;
}