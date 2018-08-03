#include <bits/stdc++.h>
#include <unordered_set>
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

int n;
int arr[MAX_N];

int ans = INF;
bool check = false;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(arr, arr + n, -arr[i]) - arr;

		if (idx != n && i != idx) {
			bool c1 = arr[i] + arr[idx] < 0;
			int v1 = abs(arr[i] + arr[idx]);
			if (ans > v1) {
				ans = v1;
				check = c1;
			}
		}
		if (idx != 0 && i != idx - 1) {
			bool c2 = arr[i] + arr[idx - 1] < 0;
			int v2 = abs(arr[i] + arr[idx - 1]);
			if (ans > v2) {
				ans = v2;
				check = c2;
			}
		}
	}
	cout << (check ? "-" : "") << ans << endl;

	return 0;
}