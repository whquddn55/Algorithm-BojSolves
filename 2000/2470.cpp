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

int n;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	int signChange = n - 1;
	for (int i = 0; i < n; ++i) 
		if (arr[i] > 0) {
			signChange = i;
			break;
		}
	int minValue = INF * 2;
	pii result;

	if ((signChange >= 2) && (minValue > abs(arr[signChange - 2] + arr[signChange - 1]))) {
		minValue = abs(arr[signChange - 2] + arr[signChange - 1]);
		result = pii(arr[signChange - 2], arr[signChange - 1]);
	}
	if ((signChange < n - 1) && (minValue > abs(arr[signChange] + arr[signChange + 1]))) {
		minValue = abs(arr[signChange] + arr[signChange + 1]);
		result = pii(arr[signChange], arr[signChange + 1]);
	}
	for (int i = 0; i < signChange; ++i) {
		int pairIndex = lower_bound(arr, arr + n, -arr[i]) - arr;
		for (int j = -1; j < 1; ++j) {
			if (pairIndex + j >= n)
				break;
			if (pairIndex + j == i)
				continue;
			if (minValue > abs(arr[i] + arr[pairIndex + j])) {
				minValue = abs(arr[i] + arr[pairIndex + j]);
				result = pii(arr[i], arr[pairIndex + j]);
			}
		}
	}
	cout << result << endl;
	
	
	return 0;
}