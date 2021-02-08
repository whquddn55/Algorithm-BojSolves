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

#define MAX_N 4000005

int n, m, k;
int arr[MAX_N];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
		cin >> arr[i];
	sort(arr, arr + m);

	while (k--) {
		int query;
		cin >> query;

		int sIndex = upper_bound(arr, arr + m, query) - arr;
		int eIndex = upper_bound(arr, arr + m, arr[sIndex]) - arr;
		cout << arr[sIndex] << endl;
		if (sIndex) 
			for (int i = sIndex; i < eIndex; ++i)
				arr[i] = arr[sIndex - 1];
		else
			for (int i = sIndex; i < eIndex; ++i)
				arr[i] = -1;
	}
	
	return 0;
}