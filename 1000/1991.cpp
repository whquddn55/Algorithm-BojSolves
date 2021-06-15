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
#define MAX_N 300005
#define MOD 9901

int n;
pii node[27];

void dfs1(int here) {
	cout << (char)(here + 'A');
	if (node[here].first != -1)
		dfs1(node[here].first);
	if (node[here].second != -1)
		dfs1(node[here].second);
}

void dfs2(int here) {
	if (node[here].first != -1)
		dfs2(node[here].first);
	cout << (char)(here + 'A');
	if (node[here].second != -1)
		dfs2(node[here].second);
}

void dfs3(int here) {
	if (node[here].first != -1)
		dfs3(node[here].first);
	if (node[here].second != -1)
		dfs3(node[here].second);
	cout << (char)(here + 'A');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b == '.')
			b = -1;
		else
			b -= 'A';
		if (c == '.')
			c = -1;
		else
			c -= 'A';

		node[a - 'A'] = {b, c};
	}

	dfs1(0);
	cout << endl;
	dfs2(0);
	cout << endl;
	dfs3(0);
	
    return 0;
}