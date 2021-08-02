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
int a, b, c;
int arr[MAX_N];
ll pSum[MAX_N];
ll dp[MAX_N];
int xpos[MAX_N];
int st[MAX_N];

ll calc(ll value) {
	return a * value * value + b * value + c;
}

double getCross(int p, int q) {
	ll k1 = -2*a*pSum[p], k2 = -2*a*pSum[q];
	ll m1 = calc(-pSum[p]) - c + dp[p], m2 = calc(-pSum[q]) - c + dp[q];
	return (double)(m2 - m1) / (k1 - k2);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> a >> b >> c;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	for (int i = 1; i <= n; ++i)
		pSum[i] = pSum[i - 1] + arr[i];

	int scnt = 0;
	int pt = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i] = calc(pSum[i]);
		if (scnt) {
			while(pt < scnt && xpos[pt + 1] < pSum[i])
				++pt;
			int j = st[pt];
			dp[i] = max(dp[i], dp[j] + calc(pSum[i] - pSum[j]));

			while(scnt > 1 && xpos[scnt] > getCross(st[scnt], i))
				--scnt;
			st[++scnt] = i;
			xpos[scnt] = getCross(st[scnt - 1], i);
			if (pt > scnt)
				pt = scnt;
		}
		else {
			st[++scnt] = i;
			xpos[scnt] = -INF;
		}
	}

	cout << dp[n] << endl;


	return 0;
}
