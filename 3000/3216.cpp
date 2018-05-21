#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100001

int n;
pii arr[MAX_N];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	for (int i = 1; i < n; i++) {
		arr[i].first += arr[i - 1].first;
		arr[i].second += arr[i - 1].second;
	}
	ans = arr[0].second;
	for (int i = 1; i < n; i++)
		ans = max(ans, arr[i].second - arr[i - 1].first);
	cout << ans << endl;
	return 0;
}