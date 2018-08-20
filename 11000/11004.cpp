#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 5000000

int n, k;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	nth_element(arr, arr +  k - 1, arr + n);
	cout << arr[k - 1] << endl;
	
	return 0;
}