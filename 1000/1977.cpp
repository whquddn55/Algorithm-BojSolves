#include <bits/stdc++.h>
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

#define MAX_N 100

int n, m;
pii ans = { 0, INF };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= 100; i++)
		if (i * i >= n && i * i <= m) {
			ans.first += i * i;
			ans.second = min(ans.second, i * i);
		}
	if (ans.first == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans.first << endl << ans.second << endl;

	return 0;
}