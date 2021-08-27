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
#define MAX_N 1000000000005
#define MOD 1000003

ll n;
vector<ll> ans;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	ans.push_back(1);
	ans.push_back(2);
	for (ll i = 2; i < sqrt(MAX_N); ++i)
		for (ll j = i * i; j < MAX_N; j *= 2)
			ans.push_back(j);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	
	cin >> n;
	cout << n - (upper_bound(ans.begin(), ans.end(), n) - ans.begin()) << endl;

	return 0;
}
