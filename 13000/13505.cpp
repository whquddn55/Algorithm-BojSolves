#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 100005
#define MOD 1'000'000'007

struct Trie {
	Trie* children[2];
	
	void insert(int value, int depth = 31) {
		if (depth == -1) {
			return;
		}
		int t = !!(value & (1 << depth));
		if (children[t] == nullptr) 
			children[t] = new Trie();
		children[t]->insert(value, depth - 1);
	}

	int find(int value, int depth = 31) {
		if (depth == -1) {
			return 0;
		}
		int t = !!(value & (1 << depth));
		if (children[t] != nullptr) 
			return children[t]->find(value, depth - 1) | (1 << depth);
		if (children[!t] != nullptr) 
			return children[!t]->find(value, depth - 1);
		return 0;
	}
};

int n;
Trie* root = new Trie();

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		ans = max(ans, root->find(~t));
		root->insert(t);
	}
	cout << ans << endl;

	return 0;
}