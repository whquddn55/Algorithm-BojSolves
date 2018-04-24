#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 200001

int n;
ll k;
vector<int> adj[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		if (u != -1)
			adj[i].push_back(u);
		if (v != -1)
			adj[i].push_back(v);
	}
	cin >> k;
	
	int here = 1;
	int ans;
	while (true) {
		if (adj[here].size() == 0) {
			ans = here;
			break;
		}
		else if (adj[here].size() == 1)
			here = adj[here][0];
		else {
			if (k % 2) {
				here = adj[here][0];
				k /= 2;
				k++;
			}
			else {
				here = adj[here][1];
				k /= 2;
			}
		}
	}
	cout << ans << endl;

	return 0;
}