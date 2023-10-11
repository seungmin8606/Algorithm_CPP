/*
BoJ 11729	골드 5
하노이 탑 이동 순서
*/

#include <iostream>
#include <cmath>

using namespace std;

int N;

void solve(int n, int start, int dest, int rest);

int main()
{
	cin >> N;

	cout << (int)pow(2, N) - 1 << endl;
	solve(N, 1, 3, 2);

	return 0;
}

void solve(int n, int start, int dest, int rest) {
	if (n == 1) {
		//cout << start << " " << dest << endl;
		printf("%d %d\n", start, dest);
		return;
	}

	solve(n - 1, start, rest, dest);
	//cout << start << " " << dest << "\n";
	printf("%d %d\n", start, dest);
	solve(n - 1, rest, dest, start);
}
