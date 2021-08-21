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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 1000005
#define MOD 1000003

int n;
int arr[MAX_N];
int sum[50];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		int t = arr[i];
		for (int j = 39; j >= 0; --j) {
			sum[j] += t % 2;
			t >>= 1;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int t = arr[i];
		for (int j = 39; j >= 0; --j) {
			sum[j] -= t % 2;
			t >>= 1;
		}
		ll calc = 0;
		int up = 0;
		ll offset = 1;
		for (int j = 39; j >= 0; --j) {
			if (arr[i] % 2) {
				calc |= (((n - 1 - i - sum[j]) + up) % 2) ? offset : 0;
				up = ((n - 1 - i - sum[j]) + up) / 2;
			}
			else {
				calc |= ((sum[j] + up) % 2) ? offset : 0;
				up = (sum[j] + up) / 2;
			}
			offset <<= 1;
			arr[i] >>= 1;
		}
		ans += calc;
	}
	cout << ans << endl;

	return 0;
}
