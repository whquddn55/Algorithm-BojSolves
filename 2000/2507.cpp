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

#define MAX_N 500

int n;
pair<pii, bool> arr[MAX_N];
bool canGo[MAX_N][MAX_N]; // i번째 발판에서 j번째 발판으로 갈 수 있나?
int dp[MAX_N][MAX_N]; // 갈 때 idx1을 밝고, 올 때 idx2를 밟는 경우의 수

int getDp(int idx1, int idx2) {
	if (idx1 == n - 1 || idx2 == n - 1)
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = canGo[idx1][n - 1] && canGo[n - 1][idx2];
	for (int next = max(idx1, idx2) + 1; next < n; next++) {
		if (canGo[idx1][next])
			ret += getDp(next, idx2);
		ret %= 1000;
		if (canGo[next][idx2])
			ret += getDp(idx1, next);
		ret %= 1000;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (arr[i].first.first + arr[i].first.second >= arr[j].first.first)
				canGo[i][j] = true;
			if (arr[j].first.first - arr[j].first.second <= arr[i].first.first && arr[j].second)
				canGo[j][i] = true;
		}

	memset(dp, -1, sizeof(dp));
	cout << getDp(0, 0) << endl;

	return 0;
}