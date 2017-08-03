#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 31;
int DP[MAXSIZE];

int main() {
	int n;
	cin >> n;

	if (n % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	DP[0] = 1;
	DP[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		DP[i] += 3 * DP[i - 2];
		for (int j = 4; j <= i; j += 2) {
			DP[i] += 2 * DP[i - j];
		}
	}

	cout << DP[n] << endl;

	return 0;
}