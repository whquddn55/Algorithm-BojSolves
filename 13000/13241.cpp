#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

ll a, b;

ll euclid(ll a, ll b) {
	if (b == 0)
		return a;

	return euclid(b, a % b);
}

int main() {
	scanf("%lld %lld", &a, &b);

	printf("%lld\n", a * b / euclid(a, b));

	return 0;
}