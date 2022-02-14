#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 200005
#define MOD 1'000'000'007

int n;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	arr.reserve(n);
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		auto it = lower_bound(all(arr), t);
		if (it == arr.end())
			arr.emplace_back(t);
		else {
			*it = t;
		}
	}
	cout << n - arr.size() << endl;
	
	return 0;
}