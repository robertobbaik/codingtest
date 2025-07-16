#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		dq.push_back(i + 1);
	}

	int commands = 0;
	
	for(int i = 0; i < M; i++)
	{
		int target;
		cin >> target;
		
		int pos = 0;

		for(int j = 0; i < dq.size(); j++)
		{
			if(dq[j] == target)
			{
				pos = j;
				break;
			}
		}

		
	}

	cout << commands << endl;
	return 0;
}