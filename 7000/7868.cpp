#include <cstdio>
#include <algorithm>
using std::sort;

int main() {
	long long a, b, c, t;
	const long long MAX = 2000000000000000000LL;
	long long ans[300000];
	int cnt = 0;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &t);
	for (long long i = 1; i < MAX / a; i *= a) 
		for (long long j = 1; j < MAX / b; j *= b) 
			for (long long k = 1; k < MAX / c; k *= c) {
				if (i * j * k == 1)
					continue;
				if (j < MAX / k && i < MAX / (j * k))
					ans[cnt++] = i * j * k;
			}
	sort(ans, ans + cnt);
	printf("%lld\n", ans[t - 1]);

	return 0;
}