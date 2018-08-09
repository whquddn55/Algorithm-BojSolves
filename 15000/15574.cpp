#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

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

#define MAX_N 1000

int n;
pii arr[MAX_N];
double dp[MAX_N];

double ans = 0.0;

double dist(pii a, pii b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double getDp(int idx1) {
	if (idx1 == 0)
		return 0;

	double& ret = dp[idx1];
	if (ret != -1.0)
		return ret;


	ret = 0.0;
	int idx = idx1 - 1;
	while (idx >= 0 && arr[idx].first == arr[idx1].first)
		idx--;
	for (int i = idx; i >= 0 && arr[i].first == arr[idx].first; i--)
		ret = max(ret, getDp(i) + dist(arr[i], arr[idx1]));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++)
		dp[i] = -1.0;

	for (int i = n - 1; i >= 0 && arr[i].first == arr[n - 1].first; i--) 
		ans = max(ans, getDp(i));
	
	cout.precision(10);
	cout << fixed;
	cout << ans << endl;

	return 0;
}
