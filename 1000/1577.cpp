#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

int n, m;
int k;
ll dp[101][101];
vector<pair<pii, pii>> arr;

ll getDp(int idx1, int idx2) {
	if (idx1 == -1 || idx2 == -1)
		return 0;
	if (idx1 == 0 && idx2 == 0)
		return dp[idx1][idx2] = 1;

	ll& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = 0;

	if (!binary_search(arr.begin(), arr.end(), make_pair(pii(idx1 - 1, idx2), pii(idx1, idx2))))
		ret += getDp(idx1 - 1, idx2);
	if (!binary_search(arr.begin(), arr.end(), make_pair(pii(idx1, idx2 - 1), pii(idx1, idx2))))
		ret += getDp(idx1, idx2 - 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> m >> n;
	cin >> k;
	arr.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> arr[i].first.second >> arr[i].first.first >> arr[i].second.second >> arr[i].second.first;
		if (arr[i].first.first > arr[i].second.first)
			swap(arr[i].first, arr[i].second);
		if (arr[i].first.second > arr[i].second.second)
			swap(arr[i].first, arr[i].second);
	}
	sort(arr.begin(), arr.end());

	memset(dp, -1, sizeof(dp));
	cout << getDp(n, m) << endl;

#ifdef DEBUG	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}
#endif

	return 0;
}
