/*
BoJ 10994	실버 4
별 찍기 - 19
*/
#include <iostream>

using namespace std;

char arr[397][397];

void draw(int n, int row, int col);
void draw_square(int k, int row, int col);

int main() {
	int N, k;

	cin >> N;

	for (int i = 0; i < 4 * N - 3; i++) {
		for (int j = 0; j < 4 * N - 3; j++)
			arr[i][j] = ' ';
	}

	draw(N, 0, 0);

	for (int i = 0; i < 4 * N - 3; i++) {
		for (int j = 0; j < 4 * N - 3; j++)
			cout << arr[i][j];
		cout << '\n';
	}

	return 0;
}

void draw(int n, int row, int col) {
	int k = 4 * n - 3;

	draw_square(k, row, col);

	if (n == 1)
		return;

	draw(n - 1, row + 2, col + 2);
}

void draw_square(int k, int row, int col) {
	for (int i = 0; i < k; i++) {
		arr[row][col + i] = '*';
		arr[row + i][col] = '*';
		arr[row + i][col + k - 1] = '*';
		arr[row + k - 1][col + i] = '*';
	}
}
