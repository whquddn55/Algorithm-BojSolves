#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MX = 202020;
const ll INF = 9e15;
ll n, x, a[MX], cnt, chk[MX], num;
int main() {
	cin.tie(0); 
	ios_base::sync_with_stdio(0);
	cin >> n >> x;
	x *= 2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] *= 2;
	}

	sort(a, a + n);

	ll s = 0;
	num = n;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == x) {
			num -= 1;
			cnt++;
			continue;
		}
		if (i <= s) break;

		while(a[i] + a[s] < x/2 && i > s) {
			s++;
		}
		if (i == s) break;
		num -= 2;
		cnt++;
		s++;
	}
	cout << cnt + num/3;
}
