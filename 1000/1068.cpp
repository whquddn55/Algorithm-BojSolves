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

int n;
int root;
int ans;
int toIgnore;
vector<int> child[MAX_N];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == -1)
			root = i;
		else
			child[t].push_back(i);
	}
	cin >> toIgnore;

	if (root != toIgnore)
		q.push(root);
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		bool pushed = false;
		for (auto next : child[here])
			if (next != toIgnore) {
				q.push(next);
				pushed = true;
			}
		if (!pushed)
			ans++;
	}
	cout << ans << endl;

	return 0;
}
