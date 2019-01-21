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

#define MAX_N 1000005

int n, k;
int arr[MAX_N];
multiset<int> ms;
int ans = INF;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	sort(arr, arr + n);
	
	for (int i = 1; i < n - k; ++i)
		ms.insert(arr[i] - arr[i - 1]);
	ans = arr[n - k - 1] - arr[0] + *ms.begin();

	for (int i = n - k; i < n; ++i) {
		ms.erase(ms.find(arr[i - (n - k) + 1] - arr[i - (n - k)]));
		ms.insert(arr[i] - arr[i - 1]);

		ans = min(ans, arr[i] - arr[i - (n - k) + 1] + *ms.begin());
	}
	cout << ans << endl;
	
	return 0;
}