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

#define MAX_N 100000
#define MAX_Q 5000

int n, q;
pii arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int idx1 = lower_bound(arr, arr + n, pii(a, -INF)) - arr;
		int idx2 = upper_bound(arr, arr + n, pii(b, INF)) - arr;
		int ans = 0;
		for (int i = idx1; i < idx2; i++) 
			if (arr[i].second >= c && arr[i].second <= d)
				ans++;
		cout << ans << endl;
	}

	return 0;
}
