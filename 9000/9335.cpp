#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 21

int n;
int on[MAX_N];
vector<int> adj[MAX_N];

int ans = INF;

void getAns(int toOn, int cnt) {
	bool isEnd = true;
	for (int i = 1; i <= n; i++)
		if (!on[i])
			isEnd = false;
	if (isEnd) {
		ans = min(ans, cnt + 1);
		return;
	}

	for (int i = toOn + 1; i <= n; i++) {
		on[i]++;
		for (int j = 0; j < adj[i].size(); j++)
			on[adj[i][j]]++;

		getAns(i, cnt + 1);

		on[i]--;
		for (int j = 0; j < adj[i].size(); j++)
			on[adj[i][j]]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(on, 0, sizeof(on));
		for (int i = 0; i < MAX_N; i++)
			adj[i].clear();
		ans = INF;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			while (num--) {
				int t;
				cin >> t;
				adj[i].push_back(t);
			}
		}

		getAns(0, -1);

		cout << ans << endl;
	}

	return 0;
}