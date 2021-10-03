#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MX = 202020;
ll n, m, a[MX], ret = 1'000'000'000'000'000'000, ta, tb;
int main() {
	cin.tie(0); 
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	tb = n;
	for (int i = 0; i < n - 1; i++) {
		ta++;
		tb--;
		ll va = a[n-i-1] * ta;
		ll vb = tb * a[0];

		ret = min(ret, (m + va + vb - 1) / (va + vb));
	}
	cout << ret;
}
