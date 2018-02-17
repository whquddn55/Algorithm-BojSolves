#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

ll n, m;

ll euclid(ll a, ll b) {
	if (b == 0)
		return a;

	return euclid(b, a % b);
}

int main() {
	scanf("%lld %lld", &n, &m);
	ll gcd = euclid(n, m);
	for (ll i = 0; i < gcd; i++)
		printf("1");

	return 0;
}