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
#define MAX_N 100005
#define MOD 1000000007

int n, m, k;
int start[MAX_N];
int nxt[MAX_N];

int dp[35][MAX_N];


int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> k >> m;
	--m;
	for (int i = 0; i < n; ++i)
		cin >> start[i];
	for (int i = 1; i <= k; ++i) {
		cin >> nxt[i];
		dp[0][i] = nxt[i];
	}

	for (int j = 1; j < 35; ++j) 
		for (int i = 1; i <= k; ++i) 
			dp[j][i] = dp[j - 1][dp[j - 1][i]];

	for (int i = 0; i < n; ++i) {
		int here = start[i];
		int remain = m;
		while(remain) {
			int idx = (int)log2(remain);
			here = dp[idx][here];
			remain -= (1<<idx);
		}
		cout << here << ' ';
	}
	return 0;
}
