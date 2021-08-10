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
#define MAX_N 1000005
#define MOD 1000000007

int n;
string s;
int pi[MAX_N];
int ans[MAX_N];

void getPi() {
	pi[0] = 0;
	int from = 1, matched = 0;
	while(from + matched < n) {
		if (s[from + matched] == s[matched]) {
			++matched;
			pi[from + matched - 1] = matched;
		}
		else if (matched == 0) {
			++from;
		}
		else {
			from += matched;
			from -= pi[matched - 1];
			matched = pi[matched - 1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	cin >> n >> s;
	getPi();
	
	ll sum = 0;

	for (int i = 0; i < n; ++i) {
		if (pi[i] == 0)
			continue;
		if (ans[pi[i] - 1] == 0)
			ans[i] = pi[i];
		else
			ans[i] = ans[pi[i] - 1];
		
		sum += (i + 1 - ans[i]);
	}
	cout << sum << endl;
	return 0;
}
