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

int n, m, k;
pii arr[MAX_N];
int lis[MAX_N];
int lisIndex = 1;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i)
		cin >> arr[i];
	sort(arr, arr + k);

	for (int i = 0; i < k; ++i) {
		if (lis[lisIndex - 1] > arr[i].second) {
			lis[lisIndex] = arr[i].second;
			lisIndex++;
		}
		else{
			*lower_bound(lis, lis + lisIndex, arr[i].second, greater<int>()) = arr[i].second;
		}
	}
	cout << lisIndex << endl;
}