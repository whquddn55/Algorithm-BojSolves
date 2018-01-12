#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main() {
	cin >> n >> m >> k;

	while (k > 0) {
		if (n > (m * 2)) {
			k -= (n - (m * 2));
			n = m * 2;
		}
		else if (n < (m * 2)) {
			k -= (m - n / 2);
			m = n / 2;
		}
		else if (n == (m * 2)) {
			if (k % 3 == 0)
				m++;
			m -= (k / 3 + 1);

			k = 0;
		}
	}

	cout << m << endl;

	return 0;
}