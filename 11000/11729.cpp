#include <bits/stdc++.h>
using namespace std;

int n;

void hanoi(int num, int from, int temp, int to) {
	if (num == 1)
		printf("%d %d\n", from, to);
	else {
		hanoi(num - 1, from, to, temp);
		printf("%d %d\n", from, to);
		hanoi(num - 1, temp, from, to);
	}
}

int main() {
	cin >> n;

	int result = 1;
	for (int i = 0; i < n; i++)
		result *= 2;

	printf("%d\n", result - 1);
	hanoi(n, 1, 2, 3);

	return 0;
}