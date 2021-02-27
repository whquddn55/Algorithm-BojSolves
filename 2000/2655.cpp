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

#define MAX_N 105
#define MOD 1000000007

int n;
pair<pii, pii> arr[MAX_N];
int dp[MAX_N];
int prv[MAX_N];

int getDp(int here) {
	int& ret = dp[here];
	if (ret != -1)
		return ret;

	ret = arr[here].first.second;

	for (int i = 0; i < here; ++i)
		if (arr[i].second.first < arr[here].second.first) {
			int result = getDp(i);
			if (ret < result + arr[here].first.second) {
				ret = result + arr[here].first.second;
				prv[here] = i;
			}
		}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	memset(prv, -1, sizeof(prv));

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second.first;
		arr[i].second.second = i + 1;
	}
	sort(arr, arr + n);

	int maxValue = -1;
	int here = 0;
	for (int i = 0; i < n; ++i) {
		getDp(i);
		if (maxValue < dp[i]) {
			maxValue = dp[i];
			here = i;
		}
	}

	stack<int> st;
	st.emplace(here);
	while (prv[here] != -1) {
		here = prv[here];
		st.emplace(here);
	}

	cout << st.size() << endl;
	while (st.size()) {
		cout << arr[st.top()].second.second << endl;
		st.pop();
	}
	
	
	return 0;
}