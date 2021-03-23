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
#define MOD 1000000007

#define MAX_N 1000000

int n;
ll arr[MAX_N];

ll get(int l, int r) {
	int mid = (l + r) / 2;
	if (l == r)
		return arr[l] * arr[l];
	if (r - l == 1)
		return max({
			(arr[l] + arr[r]) * min(arr[l], arr[r]),
			arr[l] * arr[l],
			arr[r] * arr[r]
			});

	ll r1 = get(l, mid);
	ll r2 = get(mid + 1, r);

	int left = mid, right = mid + 1;
	ll r3 = 0;
	ll sum = arr[left] + arr[right];
	ll mini = min(arr[left], arr[right]);
	while (true) {
		r3 = max(r3, sum * mini);
		if (left == l && right == r) 
			break;
		
		if (left > l && right < r) {
			if (arr[left - 1] > arr[right + 1]) {
				left--;
				sum += arr[left];
				mini = min(mini, arr[left]);
			}
			else {
				right++;
				sum += arr[right];
				mini = min(mini, arr[right]);
			}
		}
		else if (left > l) {
			left--;
			sum += arr[left];
			mini = min(mini, arr[left]);
		}
		else {
			right++;
			sum += arr[right];
			mini = min(mini, arr[right]);
		}
	}

	
	return max({ r1, r2, r3 });
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << get(0, n - 1) << endl;
	
	return 0;
}