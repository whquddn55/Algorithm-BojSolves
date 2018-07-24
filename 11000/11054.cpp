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

#define MAX_N 1000

int n;
int arr[MAX_N];
int dp1[MAX_N];
int dp2[MAX_N];

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp1[0] = 1;
	for (int i = 1; i < n; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i])
				dp1[i] = max(dp1[i], dp1[j] + 1);
	}

	dp2[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = n - 1; j > i; j--)
			if (arr[j] < arr[i])
				dp2[i] = max(dp2[i], dp2[j] + 1);
	}

	for (int i = 0; i < n; i++) 
		ans = max(ans, dp1[i] + dp2[i]);
	cout << ans - 1 << endl;

	return 0;
}
