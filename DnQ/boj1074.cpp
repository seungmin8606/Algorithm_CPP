/*
BoJ 1074	실버 1	분할정복
Z
*/

#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int length, num;
int ans = 0;

void solve(int x, int y, int len, int n, bool hor) {
	if (x == r && y == c) {
		cout << ans;
		return;
	}
	else {
		if (hor) {
			if (r >= x + len) {
				ans += n;
				x += len;
			}
			solve(x, y, len, n / 2, false);
		}
		else {
			if (c >= y + len) {
				ans += n;
				y += len;
			}
			solve(x, y, len / 2, n / 2, true);
		}
	}
}

int main() {
	cin >> N >> r >> c;

	length = pow(2, N);
	num = length * length;

	solve(0, 0, length / 2, num / 2, true);
}
