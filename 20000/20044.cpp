#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAX_N 100005

int n;
int arr[MAX_N];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;
	n *= 2;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];
	sort(arr, arr + n);

	int ans = INT_MAX;
	for (int i = 0; i < n / 2; i += 1) {
		ans = min(ans, arr[i] + arr[n - 1 - i]);
	}
	cout << ans << endl;

	return 0;
}