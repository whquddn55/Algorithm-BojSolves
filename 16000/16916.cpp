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

string s;
string p;
int pi[MAX_N];
vector<int> matches;

void getPi() {
	pi[0] = 0;
	int from = 1, matched = 0;
	while(from + matched < p.size()) {
		if (p[from + matched] == p[matched]) {
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

void kmp() {
	int from = 0, matched = 0;
	while(from + matched < s.size()) {
		if (matched != p.size() && s[from + matched] == p[matched]) {
			++matched;

			if (matched == p.size())
				matches.push_back(from);
		}
		else if (matched == 0)
			++from;
		else {
			from += matched;
			from -= pi[matched - 1];
			matched = pi[matched - 1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	cin >> s >> p;
	getPi();
	kmp();

	cout << (matches.size() ? 1 : 0) << endl;
	
	return 0;
}
