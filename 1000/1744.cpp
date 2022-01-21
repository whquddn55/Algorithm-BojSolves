#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 51
#define MOD 1'000'000'007

int n;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	int ans = 0;
	bool picked = false;
	int index = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] >= 1)
			break;
		
		if (!picked) {
			picked = true;
			index = i;
		}
		else if (picked) {
			picked = false;
			ans += arr[i] * arr[i - 1];
		}
	}
	if (picked)
		ans += arr[index];

	for (int i = 0; i < n; ++i) {
		if (arr[i] == 1)
			++ans;
	}

	picked = false;
	index = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] <= 1)
			break;
		
		if (!picked) {
			picked = true;
			index = i;
		}
		else if (picked) {
			picked = false;
			ans += arr[i] * arr[i + 1];
		}
	}
	if (picked)
		ans += arr[index];

	cout << ans << endl;

	return 0;
}