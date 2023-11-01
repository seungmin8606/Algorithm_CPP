/*
BoJ 4779	실버 3	분할정복
칸토어 집합
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;
vector<char> str;

void solve(int start, int size) {
	int middle = start + size;

	if (size < 1)
		return;
	else {
		for (int i = middle; i < middle + size; i++)
			str[i] = ' ';
		solve(start, size / 3);
		solve(middle + size, size / 3);
	}
}

int main() {
	int length;

	while (cin >> N) {
		length = pow(3, N);

		str.assign(length, '-');

		solve(0, length / 3);

		for (int i = 0; i < length; i++) {
			cout << str[i];
		}
		cout << "\n";
	}
}
