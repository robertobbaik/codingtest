#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> sequence(K);
	for (int i = 0; i < K; i++)
	{
		cin >> sequence[i];
	}

	set<int> multitap;
	int count = 0;

	for (int i = 0; i < K; i++)
	{
		int current = sequence[i];

		if (multitap.find(current) != multitap.end())
		{
			continue;
		}

		if (multitap.size() < N)
		{
			multitap.insert(current);
			continue;
		}

		int toRemove = -1;
		int farthest = -1;

		for (int device : multitap)
		{
			int nextUse = K;
			for (int j = i + 1; j < K; j++)
			{
				if (sequence[j] == device)
				{
					nextUse = j;
					break;
				}
			}

			if (nextUse > farthest)
			{
				farthest = nextUse;
				toRemove = device;
			}
		}

		multitap.erase(toRemove);
		multitap.insert(current);
		count++;
	}

	cout << count << endl;
	return 0;
}