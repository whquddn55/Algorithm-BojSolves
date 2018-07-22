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

#define MAX_N 51

string str;
map<string, pair<int, int>> m;
ll ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	m["black"] = { 0, 1 };
	m["brown"] = { 1, 10 };
	m["red"] = { 2, 100 };
	m["orange"] = { 3, 1000 };
	m["yellow"] = { 4, 10000 };
	m["green"] = { 5, 100000 };
	m["blue"] = { 6, 1000000 };
	m["violet"] = { 7, 10000000 };
	m["grey"] = { 8, 100000000 };
	m["white"] = { 9, 1000000000 };

	cin >> str;
	ans = m[str].first;
	cin >> str;
	ans = ans * 10 + m[str].first;
	cin >> str;
	cout << ans * m[str].second;
 	
	return 0;
}
