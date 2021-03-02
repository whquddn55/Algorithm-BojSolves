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

#define MAX_N 10005
#define MOD 1000000007

int n;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i];

	sort(arr, arr + n);

	ll result = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > 0)
			break;
		for (int j = i + 1; j < n; ++j) {
			if (arr[i] + arr[j] > 0)
				break;
			
			
 			int index1 = lower_bound(arr + j + 1, arr + n, -(arr[i] + arr[j])) - arr;
			int index2 = upper_bound(arr + j + 1, arr + n, -(arr[i] + arr[j])) - arr;
			
			if ((index1 != n) && (arr[index1] == -(arr[i] + arr[j]))) {
				result += index2 - index1;
			}
		}
	}
	cout << result << endl;

	return 0;
}