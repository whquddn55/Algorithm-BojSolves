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
#define MOD 1000000007

#define MAX_N 1000005

int n;
vector<int> adj[MAX_N];
int parent[MAX_N];
int dp[MAX_N][2];

int getDp(int idx1, int idx2) {
	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;


	ret = idx2;
	if (idx2 == 0) {
		for (int child : adj[idx1]) {
			if (parent[idx1] == child)
				continue;
			parent[child] = idx1;
			ret += getDp(child, 1);
		}
	}
	else {
		for (int child : adj[idx1]) {
			if (parent[idx1] == child)
				continue;
			parent[child] = idx1;
			ret += min(getDp(child, 0), getDp(child, 1));
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int f, t;
		cin >> f >> t;
		f--;
		t--;
		adj[f].emplace_back(t);
		adj[t].emplace_back(f);
	}


	memset(dp, -1, sizeof(dp));
	memset(parent, -1, sizeof(parent));
	cout << min(getDp(0, 0), getDp(0, 1)) << endl;


	return 0;
}