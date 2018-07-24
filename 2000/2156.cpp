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

#define MAX_N 10000

int n;
int arr[MAX_N];
int dp[MAX_N];

int getDp(int idx1) {
	if (idx1 == 0)
		return arr[0];
	if (idx1 == 1)
		return arr[0] + arr[1];
	if (idx1 == 2)
		return max({arr[0] + arr[1], arr[0] + arr[2], arr[1] + arr[2]});

	int& ret = dp[idx1];
	if (ret != -1)
		return ret;

	return ret = max({getDp(idx1 - 1), getDp(idx1 - 2) + arr[idx1] ,arr[idx1] + arr[idx1 - 1] + getDp(idx1 - 3)});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << getDp(n - 1) << endl;

	return 0;
}
