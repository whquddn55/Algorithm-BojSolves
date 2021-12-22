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
#define MAX_N 3005
#define MOD 1'000'000'007

int m;
string s;
int cnt[MAX_N][27];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> m >> s;
	int ans = INF;
	for (int len = 1; len <= m; ++len) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.size(); ++i) 
			cnt[i % len][s[i] - 'A']++;
		
		int temp = 0;
		for (int i = 0; i < len; ++i) {
			int sum = 0;
			int maxV = 0;
			for (int j = 0; j < 26; ++j) {
				sum += cnt[i][j];
				maxV = max(maxV, cnt[i][j]);
			}
			temp += sum - maxV;
		}
		ans = min(ans, temp);
	}	
	cout << ans << endl;
	
	return 0;
}