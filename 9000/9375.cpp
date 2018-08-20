#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 31

int n;
int dp[MAX_N];
vector<int> arr;
map<string, int> group;

int ans = 0;

int getDp(int idx1) {
	if (idx1 == arr.size())
		return 1;
	int& ret = dp[idx1];
	if (ret != -1)
		return ret;

	ret = 1;
	return ret = getDp(idx1 + 1) + getDp(idx1 + 1) * arr[idx1];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		group.clear();
		arr.clear();
		ans = 0;

		cin >> n;
		while (n--) {
			string a, b;
			cin >> a >> b;
			group[b]++;
		}

		for (auto e : group)
			arr.emplace_back(e.second);

		memset(dp, -1, sizeof(dp));
		cout << getDp(0) - 1 << endl;
	}
	return 0;
}