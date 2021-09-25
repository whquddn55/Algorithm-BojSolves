#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
const ll MX = 505050;
const ll INF = 9e15;
const ll MOD = 998'244'353;
ll n, m, c1, c2, a[MX], b[MX], cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	cin >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll mi = INF;
	for (int i = 0; i < m; i++) {
		cin >> b[i];

		auto it = lower_bound(a, a + n, b[i]);

		if (it != a + n) {
			ll d = abs(c1 - c2) + abs(*it - b[i]);
			if (mi > d) {
				mi = d;
				cnt = 1;
			}
			else if (d == mi) {
				cnt++;
			}
		}
		if (it != a) {
			it--;
			ll d = abs(c1 - c2) + abs(*it - b[i]);
			if (mi > d) {
				mi = d;
				cnt = 1;
			}
			else if(d == mi){
				cnt++;
			}
		}
	}
	cout << mi << " " << cnt;
}