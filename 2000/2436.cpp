#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	b /= a;

	pair<int, int> result;
	int check = INT_MAX;
	for (int i = sqrt(b) + 10; i >= 1; i--) {
		if (b % i == 0 && gcd(i, b/ i) == 1) {
			int ret1 = i;
			int ret2 = b / i;

			if (ret1 * a + ret2 * a < check) {
				result = make_pair(min(ret1, ret2) * a, max(ret1, ret2) * a);
				check = ret1 * a + ret2 * a;
			}
		}
	}

	printf("%d %d\n", result.first, result.second);


	return 0;
}