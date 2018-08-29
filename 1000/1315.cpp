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

#define MAX_N 100

struct Data {
	int s, i, p;
};

int n;
int dp[1001][1001];
Data arr[MAX_N];

int getDp(int idx1, int idx2) {
	if (idx1 >= 1000 || idx2 >= 1000) {
		cout << n << endl;
		exit(0);
	}
	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	int point = 0;
	ret = 0;
	for (int i = 0; i < n; i++)
		if (arr[i].s <= idx1 || arr[i].i <= idx2) {
			point += arr[i].p;
			ret++;
		}

	point -= idx1 + idx2 - 2;
	for (int i = 0; i <= point; i++)
		ret = max(ret, getDp(idx1 + i, idx2 + point - i));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].s >> arr[i].i >> arr[i].p;

	memset(dp, -1, sizeof(dp));
	cout << getDp(1, 1) << endl;

	return 0;
}