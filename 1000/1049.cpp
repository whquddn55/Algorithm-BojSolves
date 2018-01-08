#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int minPackageCost = INT_MAX;
	int minPieceCost = INT_MAX;
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;

		minPackageCost = min(temp1, minPackageCost);
		minPieceCost = min(temp2, minPieceCost);
	}

	int result = minPieceCost * n;
	int cnt = 0;
	while (n >= 0) {
		n -= 6;

		cnt++;
		int sum = minPackageCost * cnt;
		if (n >= 0)
			sum += n * minPieceCost;

		result = min(result, sum);
	}

	cout << result << endl;

	return 0;
}