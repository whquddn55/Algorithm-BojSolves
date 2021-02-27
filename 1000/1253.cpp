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

#define MAX_N 2005
#define MOD 1000000007

int n;
int arr[MAX_N];
bool isGood[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int index = lower_bound(arr, arr + n, arr[i] + arr[j]) - arr;
			int index2 = upper_bound(arr, arr + n, arr[i] + arr[j]) - arr;
			if (index != i && index != j && index != n && (arr[index] == arr[i] + arr[j])) {
				if (!isGood[index]) {
					while (index != index2) {
						isGood[index] = true;
						index++;
					}
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; ++i)
		result += isGood[i];
	cout << result << endl;
	
	
	return 0;
}