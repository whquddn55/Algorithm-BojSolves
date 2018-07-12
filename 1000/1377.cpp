#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)

#define MAX_N 500000

int n;
int arr[MAX_N];
int sarr[MAX_N];

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sarr[i] = arr[i];
	}
	sort(sarr, sarr + n);

	for (int i = 0; i < n; i++) {
		int idx = upper_bound(sarr, sarr + n, arr[i]) - sarr;
		ans = max(ans, i - idx + 1);
	}
	cout << ans + 1 << endl;


	
	return 0;
}