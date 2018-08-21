#include <bits/stdc++.h>
#include <cassert>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 500

int n, m;
bool isF[MAX_N][MAX_N];

int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		isF[u][v] = isF[v][u] = true;
	}

	for (int i = 1; i < n; i++) {
		if (isF[0][i])
			ans++;
		else {
			for (int j = 1; j < n; j++)
				if (isF[0][j] && isF[j][i]) {
					ans++;
					break;
				}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}