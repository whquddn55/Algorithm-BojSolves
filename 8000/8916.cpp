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
#define MAX_N 21
#define MOD 9999991

int n;
int dv = 1;
int arr[MAX_N];
pii tree[MAX_N];
ll fact[MAX_N];

void insert(int here, int value) {
	if (here < value) {
		if (tree[here].first == 0) 
			tree[here].first = value;
		else 
			insert(tree[here].first, value);
	}
	else {
		if (tree[here].second == 0) 
			tree[here].second = value;
		else 
			insert(tree[here].second, value);
	}
}

ll dfs(int here) {
	int sum = 1;
	if (tree[here].first) 
		sum += dfs(tree[here].first);
	if (tree[here].second)
		sum += dfs(tree[here].second);
	dv = (dv * sum) % MOD;
	return sum;
}

ll power(ll a, int b) {
	ll ret = 1;
	while(b) {
		if (b % 2)
			ret = (a * ret) % MOD;
		b /= 2;
		a = (a * a) % MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	fact[0] = fact[1] = 1;
	for (int i = 2; i < MAX_N; ++i)
		fact[i] = (fact[i - 1] * i) % MOD;
	
	int tc;
	cin >> tc;
	while(tc--) {
		dv = 1;
		for (int i = 0; i < MAX_N; ++i) 
			tree[i] = {0, 0};
		
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		int root = arr[0];
		for (int i = 1; i < n; ++i)
			insert(root, arr[i]);

		dfs(root);
		cout << (fact[n] * (power(dv, MOD - 2) % MOD)) % MOD << endl;
	}

	return 0;
}
