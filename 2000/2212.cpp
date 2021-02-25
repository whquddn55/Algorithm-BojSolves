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

int n, k;
int arr[MAX_N];
pii psum[MAX_N];
set<int> sliced;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n - 1; ++i)
		psum[i] = pii(arr[i + 1] - arr[i], i);
	sort(psum, psum + n, greater<pii>());
	
	for (int i = 0; i < k - 1; ++i)
		sliced.insert(psum[i].second);
	sliced.insert(n - 1);

	int s = 0;
	int result = 0;
	for (auto e : sliced) {
		result += (arr[e] - arr[s]);
		s = e + 1;
	}
	cout << result << endl;
	

	return 0;
}