#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
const ll MX = 1010;
const ll INF = 9e15;
const ll MOD = 998'244'353;
ll n, m, a[MX][MX], f[MX][MX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		pll mx = { 0,0 };
		for (int j = 0; j < m; j++) {
			mx = max(mx, { a[i][j],j });
		}
		f[i][mx.second] = 1;
	}
	for (int i = 0; i < m; i++) {
		pll mx = { 0,0 };
		for (int j = 0; j < n; j++) {
			mx = max(mx, { a[j][i],j });
		}
		f[mx.second][i] = 1;
	}
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!f[i][j]) {
				ret += a[i][j];
			}
		}
	}
	cout << ret;
}