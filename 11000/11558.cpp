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

#define MAX_N 10000

int n;
int arr[MAX_N];

int dfs(int idx, int value) {
	if (idx == n - 1)
		return value;
	if (arr[idx] == -1)
		return 0;

	int next = arr[idx];
	arr[idx] = -1;
	dfs(next, value + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			--arr[i];
		}
		cout << dfs(0, 0) << endl;
	}
	
	return 0;
}