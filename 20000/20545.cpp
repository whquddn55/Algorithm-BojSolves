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
#define MAX_N 400005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int n, m, k, l;
pair<pll, pll> arr[MAX_N];
int weight[MAX_N];

ll score[MAX_N];
pll minDiff[MAX_N];
pll maxDiff[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> k >> l;
	for (int i = 0; i < k; ++i)
		cin >> arr[i].first >> weight[i] >> arr[i].second;

	ll a = 0;
	ll bX = 0;
	ll bY = 0;
	ll cX = 0;
	ll cY = 0;
	fill_n(minDiff, MAX_N, pll(LLONG_MAX, LLONG_MAX));
	for (int i = 0; i < k; ++i) {
		a += weight[i];
		bX += arr[i].first.first * weight[i];
		cX += arr[i].first.first * arr[i].first.first * weight[i];
		bY += arr[i].first.second * weight[i];
		cY += arr[i].first.second * arr[i].first.second * weight[i];

		score[i] = a * arr[i].second.first * arr[i].second.first - 2 * bX * arr[i].second.first + cX
			+ a * arr[i].second.second * arr[i].second.second - 2 * bY * arr[i].second.second + cY;
		
		ll minX = bX / a;
		ll minY = bY / a;
		for (int j = 0; j < 2; ++j) {
			int x = minX + j;
			for (int t = 0; t < 2; ++t) {
				int y = minY + t;
				minDiff[i] = min(minDiff[i], pll{a * x * x - 2 * bX * x + cX + a * y * y - 2 * bY * y + cY - score[i], score[i]});
			}
		}

		int dx[] = {1, n};
		int dy[] = {1, m};
		for (int j = 0; j < 2; ++j) {
			int x = dx[j];
			for (int t = 0; t < 2; ++t) {
				int y = dy[t];
				maxDiff[i] = max(maxDiff[i], pll{a * x * x - 2 * bX * x + cX + a * y * y - 2 * bY * y + cY - score[i], score[i]});
			}
		}
	}
	sort(minDiff, minDiff + k);
	sort(maxDiff, maxDiff + k, greater<pll>());

	ll ans1 = 0;
	ll ans2 = 0;
	ll ans3 = 0;
	for (int i = 0; i < l; ++i) {
		ans1 += score[i] % MOD;
		ans2 += (minDiff[i].first + minDiff[i].second) % MOD;
		ans3 += (maxDiff[i].first + maxDiff[i].second) % MOD;
		ans1 %= MOD;
		ans2 %= MOD;
		ans3 %= MOD;
	}
	for (int i = l; i < k; ++i) {
		ans1 += score[i] % MOD;
		ans2 += minDiff[i].second % MOD;
		ans3 += maxDiff[i].second % MOD;
		ans1 %= MOD;
		ans2 %= MOD;
		ans3 %= MOD;
	}
	cout << ans1 << endl;
	cout << ans3 << endl;
	cout << ans2 << endl;
	
	return 0;
}