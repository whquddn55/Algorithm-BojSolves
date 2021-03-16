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

#define MAX_N 25


int n;
pii arr[MAX_N];

double result;
pii cache;
void get(int here, int u1, int u2) {
	if (here == n) {
		result = min(result, sqrt((ll)cache.first * cache.first + (ll)cache.second * cache.second));
		return;
	}

	if (u1 < n / 2) {
		cache.first += arr[here].first;
		cache.second += arr[here].second;
		get(here + 1, u1 + 1, u2);
		cache.first -= arr[here].first;
		cache.second -= arr[here].second;
	}
	if (u2 < n / 2) {
		cache.first -= arr[here].first;
		cache.second -= arr[here].second;
		get(here + 1, u1, u2 + 1);
		cache.first += arr[here].first;
		cache.second += arr[here].second;
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cache = pii(0, 0);
		result = INF;

		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		get(0, 0, 0);
		cout.precision(10);
		cout << fixed;
		cout << result << endl;
	}

	return 0;
}