#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 300001
#define MAX_LEN 21

int n, k;
string arr[MAX_SIZE];
ll sum[MAX_SIZE][MAX_LEN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sum[0][arr[0].size()] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < MAX_LEN; j++)
			sum[i][j] = sum[i - 1][j];
		sum[i][arr[i].size()]++;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) 
		ans += sum[(i + k) >= n ? (n - 1) : (i + k)][arr[i].size()] - sum[i][arr[i].size()];
	cout << ans << endl;

	return 0;
}
