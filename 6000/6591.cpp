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

#define MAX_N 101

int n, k;
ll ans = 1;
vector<ll> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (true) {
		ans = 1;
		arr.clear();
		cin >> n >> k;
		if (n == 0 && k == 0)
			break;

		k = min(k, n - k);
		for (int i = 1; i <= k; i++)
			arr.push_back(i);
		for (int i = n - k + 1; i <= n; i++) {
			ans *= i;
			for (auto& e : arr) {
				if (ans % e == 0) {
					ans /= e;
					e = 1;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}