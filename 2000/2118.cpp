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

#define MAX_N 50001

int n;
int arr[MAX_N];

int idx, lsum, rsum, ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		rsum += arr[i];

	int prv = 0;
	for (int i = 0; i < n; i++) {
		prv = min(lsum, rsum);
		while (min((lsum + arr[idx]), (rsum - arr[idx])) > prv) {
			lsum += arr[idx];
			rsum -= arr[idx];
			idx = (idx + 1) % n;
			prv = min(lsum, rsum);
		}
		ans = max(ans, min(lsum, rsum));
		lsum -= arr[i];
		rsum += arr[i];
	}
	cout << ans << endl;

	return 0;
}
