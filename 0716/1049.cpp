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

	vector<pair<int, int>> vp(M);

	for (int i = 0; i < M; i++)
	{
		cin >> vp[i].first >> vp[i].second;
	}

	int result = 0;
	int min_package = vp[0].first;
	int min_piece = vp[0].second;

	for (int i = 0; i < M; i++)
	{
		auto [package, piece] = vp[i];

		min_package = min(min_package, package);
		min_piece = min(min_piece, piece);
	}

	if(min_piece * 6 > min_package)
	{
		if(N % 6 != 0)
		{
			int temp = (N / 6 + 1) * min_package;
			int temp2 = (N / 6) * min_package + (N % 6) * min_piece;
			
			result = min(temp, temp2);
		}
		else
		{
			result = (N/6) * min_package;
		}	
	}
	else
	{
		result = min_piece * N;
	}

	cout << result << endl;

	return 0;
}