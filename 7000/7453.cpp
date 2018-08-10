#include <bits/stdc++.h>
#include <unordered_map>
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

#define MAX_N 4000

int n;
int arr[4][MAX_N];
int a[MAX_N * MAX_N], b[MAX_N * MAX_N];

ll ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[j][i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			a[i * n + j] = (arr[0][i] + arr[1][j]);
			b[i * n + j] = (arr[2][i] + arr[3][j]);
		}
	sort(a, a + n * n);
	sort(b, b + n * n);

	int prv = 0;
	for (int i = 0; i < n * n; i++) {
		if (i && a[i] == a[i - 1])
			ans += prv;
		else 
			ans += prv = upper_bound(b, b + n * n, -a[i]) - lower_bound(b, b + n * n, -a[i]);
	}
	cout << ans << endl;

	return 0;
}
