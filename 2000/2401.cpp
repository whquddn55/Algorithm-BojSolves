#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class a, class b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<class a, class b>
istream& operator>>(istream& is, pair<a, b>& pai) {
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
short pi[MAX_M];
short len[500];
bool matched[MAX_L][500];
string s, p;

int dp[MAX_L]; // i번째에 문자열을 놓을 때 얻을 수 있는 최대 길이총합

void getPi() {
	memset(pi, 0, sizeof(pi));
	int m = p.size();
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			j++;
		pi[i] = j;
	}
}

void kmp(int num) {
	getPi();
	int m = len[num] = p.size();
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			j++;
			if (j == m) {
				matched[i][num] = true;
				j = pi[j - 1];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		kmp(i);
	}

	for (int i = 0; i < n; i++)
		if (matched[0][i])
			dp[0] = 1;

	for (int i = 1; i < s.size(); i++) {
		dp[i] = dp[i - 1];
		for (int j = 0; j < n; j++)
			if (matched[i][j])
				dp[i] = max(dp[i], i - len[j] < 0 ? len[j] : (dp[i - len[j]] + len[j]));
	}

	cout << dp[s.size() - 1] << endl;

	return 0;
}