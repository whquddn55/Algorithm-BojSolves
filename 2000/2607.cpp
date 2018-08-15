#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ostream& operator<<(ostream& os, const pair<int, int>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
istream& operator>>(istream& is, pair<int, int>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_M 10005
#define MAX_L 100005

int n;
string s, p;
int cnt[26];
int cnt2[26];
int l, g;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	cin >> s;
	for (auto e : s)
		cnt[e - 'A']++;
	n--;
	for (int i = 0; i < n; i++) {
		l = g = 0;
		memset(cnt2, 0, sizeof(cnt2));

		cin >> p;
		for (auto e : p)
			cnt2[e - 'A']++;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] - cnt2[i] < 0)
				g += cnt2[i] - cnt[i];
			else if (cnt[i] - cnt2[i] > 0)
				l += cnt[i] - cnt2[i];
		}
		if (l <= 1 && g <= 1)
			ans++;
	}
	cout << ans << endl;

	return 0;
}