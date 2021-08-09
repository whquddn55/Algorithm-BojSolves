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

string s;
int sa[MAX_N];
int gr[MAX_N];
int d = 1;

bool comp(int i, int j) {
	if (gr[i] == gr[j]) {
		i += d;
		j += d;
	}
	if (i >= s.size() || j >= s.size())
		return i > j;
	return gr[i] < gr[j];
}

void getSA() {
	for (int i = 0; i < s.size(); ++i) {
		sa[i] = i;
		gr[i] = s[i];
	}
	while(true) {
		sort(sa, sa + s.size(), comp);

		int temp[MAX_N] = {0, };
		for (int i = 0; i < s.size() - 1; ++i) 
			temp[i + 1] = temp[i] + comp(sa[i], sa[i + 1]);
		for (int i = 0; i < s.size(); ++i)
			gr[sa[i]] = temp[i];

		d *= 2;
		if (temp[s.size() - 1] == s.size() - 1)
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> s;
	getSA();
	for (int i = 0; i < s.size(); ++i)
		cout << sa[i] << endl;
	

	return 0;
}
