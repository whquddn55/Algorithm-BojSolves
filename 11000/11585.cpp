#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 2000000

int n;
int pi[MAX_N];
vector<int> matched;
string s, p;

void getPi() {
	int m = p.size();
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
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
		while (j > 0 && s[i] != p[j])
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

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		s.push_back(c);
	}
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		p.push_back(c);
	}
	for (int i = 0; i < n - 1; i++)
		s.push_back(s[i]);

	kmp();
	int a = matched.size();
	int b = n;
	int gc = gcd(a, b);
	cout << a / gc << "/" << b / gc << endl;

	return 0;
}
