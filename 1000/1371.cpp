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

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100

string str;
int cnt[26];
int maxValue = 0;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);

	while (cin >> str) {
		for (auto e : str)
			cnt[e - 'a']++;
	}
	for (auto e : cnt)
		maxValue = max(maxValue, e);
	for (int i = 0; i < 26; i++)
		if (cnt[i] == maxValue)
			cout << char(i + 'a');
	
	return 0;
}