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

#define MAX_N 1000000

int n, m;
int arr[MAX_N];
int temp[MAX_N];
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 1; i <= m; i <<= 1) {
		if (!(i&m)) continue;
		copy(arr, arr + n, temp);
		for (int j = 0; j < n; j++)
			arr[j] = (arr[j] ^ temp[(j + i) % n]);
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;

	return 0;
}