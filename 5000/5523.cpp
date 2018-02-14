#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int n;
	scanf("%d", &n);
	int re1 = 0, re2 = 0;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (t1 > t2)
			re1++;
		else if (t2 > t1)
			re2++;
	}
	printf("%d %d\n", re1, re2);

	return 0;
}