#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 3)
#define endl '\n'

ll n, k, q;
vector<ll> p1;
vector<ll> p2;

void dfs1(ll here) {
	p1.push_back(-here);
	if (here == 1)
		return;

	dfs1((here + (k - 2)) / k);
}

void dfs2(ll here) {
	p2.push_back(-here);
	if (here == 1)
		return;

	dfs2((here + (k - 2)) / k);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k >> q;
	while (q--) {
		ll x, y;
		cin >> x >> y;
		if (k == 1)
			cout << abs(y - x) << endl;
		else {
			p1.clear(); p2.clear();
			dfs1(x);
			dfs2(y);
			for (int i = 0; i < p1.size(); i++) {
				int idx = lower_bound(p2.begin(), p2.end(), p1[i]) - p2.begin();
				if (p2[idx] == p1[i]) {
					cout << i + idx << endl;
					break;
				}
			}
		}
	}
		

	return 0;
}
