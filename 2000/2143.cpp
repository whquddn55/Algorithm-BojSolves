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

#define MAX_N 1005

int t;
int n, m;
int a[MAX_N];
int b[MAX_N];
vector<int> pb;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> t;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	for (int i = 0; i < m; ++i) {
		int bSum = 0;
		for (int j = i ; j < m; ++j) {
			bSum += b[j];
			pb.emplace_back(bSum);
		}
	}
	sort(pb.begin(), pb.end());

	ll ret = 0;
	for (int i = 0; i < n; ++i) {
		int aSum = 0;
		for (int j = i; j < n; ++j) {
			aSum += a[j];
			ret += upper_bound(pb.begin(), pb.end(), t - aSum) - lower_bound(pb.begin(), pb.end(), t - aSum);
		}
	}
	cout << ret << endl;
	
	return 0;
}