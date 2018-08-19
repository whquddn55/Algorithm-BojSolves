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

#define MAX_N 11

int n;
int cnt[3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t = i;
		while (t && t % 10 == 0) {
			cnt[0]++;
			t /= 10;
		}
		while (t && t % 2 == 0) {
			cnt[1]++;
			t /= 2;
		}
		while (t && t % 5 == 0) {
			cnt[2]++;
			t /= 5;
		}
	}

	cout << cnt[0] + min(cnt[1], cnt[2]) << endl;

	return 0;
}