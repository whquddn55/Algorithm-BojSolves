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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "w", stdin);
#endif
	cin >> str;
	str[0] = -str[0];
	str[1] = -str[1];
	str[2] = -str[2];
	str[1] -= 65;
	str[2] -= 65;

	int value = str[0] * 64 * 64 + str[1] * 64 + str[2];
	cout << 91135 - value + 1 << endl;

	
	return 0;
}