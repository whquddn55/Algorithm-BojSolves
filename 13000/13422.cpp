#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100005
#define MOD 1000000007

int n, m, k;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		int sum = 0;
		for (int i = 0; i < m; ++i)
			sum += arr[i];

		int result = sum < k;
		for (int i = 1; i < n; ++i) {
			if (i - 1 == (i - 1 + m) % n)
				continue;
			sum -= arr[i - 1];
			sum += arr[(i - 1 + m) % n];
			result += (sum < k);
		}
		cout << result << endl;
	}

	return 0;
}