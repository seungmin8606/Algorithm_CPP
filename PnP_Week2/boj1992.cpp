/*
BoJ 1992	실버 1
쿼드트리
*/

#include <iostream>
#include <string>

using namespace std;

string arr[64];
int N;

void solve(int n, int row, int col);

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	solve(N, 0, 0);
}

void solve(int n, int row, int col) {
	if (n == 1) {
		cout << arr[row][col];
		return;
	}

	bool zero, one;
	zero = one = true;

	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (arr[i][j] == '1')
				zero = false;
			else
				one = false;
		}
	}
	if (zero)
		cout << 0;
	else if (one)
		cout << 1;
	else {
		cout << "(";
		solve(n / 2, row, col);
		solve(n / 2, row, col + n / 2);
		solve(n / 2, row + n / 2, col);
		solve(n / 2, row + n / 2, col + n / 2);
		cout << ")";
	}
}
