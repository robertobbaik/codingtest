#include <iostream>
using namespace std;

int N, r, c;
int result = 0;

void solve(int x, int y, int size)
{
	if (size == 1)
	{
		return;
	}

	int half = size / 2;

	if (r < x + half && c < y + half)
	{
		solve(x, y, half);
	}
	else if (r < x + half && c >= y + half)
	{
		result += half * half;
		solve(x, y + half, half);
	}
	else if (r >= x + half && c < y + half)
	{
		result += 2 * half * half;
		solve(x + half, y, half);
	}
	else
	{
		result += 3 * half * half;
		solve(x + half, y + half, half);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> r >> c;

	solve(0, 0, 1 << N);

	cout << result << endl;

	return 0;
}