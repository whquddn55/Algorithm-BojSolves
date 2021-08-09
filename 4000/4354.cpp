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
int pi[MAX_N];

void getPi() {
	pi[0] = 0;
	int start = 1, matched = 0;
	while(start + matched < s.size()) {
		if (matched < s.size() && s[start + matched] == s[matched]) {
			++matched;
			pi[start + matched - 1] = matched;
		}
		else if (matched == 0)
			++start;
		else {
			start += matched - pi[matched - 1];
			matched = pi[matched - 1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	while(true) {
		cin >> s;
		if (s.compare(".") == 0)
			break;
		
		memset(pi,0, sizeof(pi));

		getPi();
		int n = s.size();
		int l = pi[n - 1];
		if (n % (n - l))
			cout << 1 << endl;
		else 
			cout << (n / (n - l)) << endl;
	}

	return 0;
}
