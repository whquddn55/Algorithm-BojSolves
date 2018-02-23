#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int a, b, c, n;

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &n);

	for (int i = 0; i <= n; i += a) {
		for (int j = 0; j <= n; j += b) {
			for (int k = 0; k <= n; k += c) {
				if (i + j + k == n) {
					printf("1\n");
					return 0;
				}
			}
		}
	}
	printf("0\n");
	
	return 0;

}
