#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("1 1\n");
	}
	else {
		printf("%d ", (n + 2) / 3);

		int cnt = 0;
		while (n % 2 == 0) {
			n /= 2;
			cnt++;
		}
		cnt = (cnt + 1) / 2;
		for (int i = 3; i <= n; i++)
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
		printf("%d\n", cnt);
	}
	

	return 0;
}