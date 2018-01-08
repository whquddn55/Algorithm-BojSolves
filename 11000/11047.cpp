#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = n - 1; i >= 0; i--)
		cin >> coins[i];

	int result = 0;

	for (int i = 0; i < n; i++) {
		if (k < coins[i])
			continue;

		result += k / coins[i];
		k %= coins[i];
	}

	cout << result << endl;

	return 0;
}