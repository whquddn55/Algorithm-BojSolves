#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

ostream& operator<<(ostream& os, const pll& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pll& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 1000005

int pi[MAX_N];
vector<int> matched;
string s, p;

void getPi() {
	memset(pi, 0, sizeof(pi));
	int m = p.size();
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
}

void kmp() {
	getPi();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				matched.push_back(i - m + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	getline(cin, s);
	getline(cin, p);
	kmp();

	cout << matched.size() << endl;
	for (auto e : matched)
		cout << e + 1 << ' ';

	return 0;
}
