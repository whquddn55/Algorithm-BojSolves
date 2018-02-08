#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int a, b;

int main() {
	scanf("%d %d", &a, &b);
	int gap = abs(a - b);
	while (gap && !(gap % 2))
		gap /= 2;

	for (int i = 0; i < 5; i++) {
		int p, q;
		scanf("%lld %lld", &p, &q);

		bool result = false;
		if (a == b) {
			if (p == q)
				result = true;
		}
		else {
			if ((p != q) && ((ll)(a - b) * (p - q) > 0)) {
				if (abs(p - q) % gap == 0)
					result = true;
			}
		}
		printf("%s\n", result ? "Y" : "N");
	}


	return 0;
}