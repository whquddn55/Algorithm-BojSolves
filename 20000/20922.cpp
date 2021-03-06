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

#define MAX_N 200005
#define MOD 1000000007

int n, k;
int arr[MAX_N];
int cnt[100001];
int result;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int f = 0, t = 0;
	while (t < n) {
		cnt[arr[t]]++;
		if (cnt[arr[t]] > k) {
			while (arr[f] != arr[t]) {
				cnt[arr[f]]--;
				f++;
			}
			cnt[arr[f]]--;
			f++;
		}
		result = max(result, t - f + 1);
		t++;
	}
	cout << result << endl;
	
	return 0;
}