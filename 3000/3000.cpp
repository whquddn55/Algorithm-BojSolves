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

#define MAX_N 100000

int n;
pii arr[MAX_N];
int xCnt[MAX_N + 1];
int yCnt[MAX_N + 1];

ll ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		xCnt[arr[i].second]++;
		yCnt[arr[i].first]++;
	}


	for (int i = 0; i < n; i++) 
		ans += (ll)(xCnt[arr[i].second] - 1) * (yCnt[arr[i].first] - 1);
	cout << ans << endl;
	
	return 0;
}