#include <cstdio>
#include <algorithm>

using namespace std;

int a[10000];

int main() {
	int i, n, t = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (i = 0; i < n; i++) {
		t += a[i];
		if (t << 1 < i * (i + 1)) {
			puts("-1");
			return 0;
		}
	}
	puts((t << 1) == n * (n - 1) ? "1" : "-1");
	return 0;
}
