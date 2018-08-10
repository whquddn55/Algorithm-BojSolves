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

#define MAX_N 20000

int n, s;
int arr[MAX_N];

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		int temp = upper_bound(arr, arr + n, s - arr[i]) - arr - i - 1;
		if (temp < 0)
			break;
		ans += temp;
	}
	cout << ans << endl;

	return 0;
}
