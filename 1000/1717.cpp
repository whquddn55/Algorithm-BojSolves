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

#define MAX_N 1000001

int n, m;
int parent[MAX_N];

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u != v)
		parent[u] = v;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n + 1; i++)
		parent[i] = i;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a) {
			if (find(b) == find(c))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			merge(b, c);
	}

	return 0;
}