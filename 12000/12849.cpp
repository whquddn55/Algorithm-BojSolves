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

#define MAX_N 1000005
#define MOD 1000000007

int n;
int pre[8];
int arr[8];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	pre[0] = 1;

	for (int i = 0; i < n; ++i) {
		arr[0] = (pre[1] + pre[2]) % MOD;
		arr[1] = ((pre[0] + pre[2]) % MOD + pre[3]) % MOD;
		arr[2] = (((pre[0] + pre[1]) % MOD + pre[3]) % MOD + pre[4]) % MOD;
		arr[3] = (((pre[1] + pre[2]) % MOD + pre[4]) % MOD + pre[5]) % MOD;
		arr[4] = (((pre[2] + pre[3]) % MOD + pre[5]) % MOD + pre[6]) % MOD;
		arr[5] = ((pre[3] + pre[4]) % MOD + pre[7]) % MOD;
		arr[6] = (pre[4] + pre[7]) % MOD;
		arr[7] = (pre[5] + pre[6]) % MOD;

		for (int i = 0; i < 8; ++i)
			pre[i] = arr[i];
	}

	cout << arr[0] << endl;

	return 0;
}