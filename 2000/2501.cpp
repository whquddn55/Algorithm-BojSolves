#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, k;

int main() {
	scanf("%d %d", &n, &k);

	int cnt = 0;
	int i = 1;
	for (; i <= n; i++) {
		if ((n % i) == 0)
			cnt++;
		
		if (cnt == k) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0\n");

	return 0;
}