#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100000

int n;
int sum = 0;
int ans = -INT_MAX;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		sum = max(sum + t, t);
		ans = max(ans, sum);
	}
	cout << ans << endl;

	return 0;
}