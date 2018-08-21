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

#define MAX_N 10000

int n;
int arr[MAX_N];

void get(int s, int e) {
	if (s > e)
		return;
	/*cout << pii(s, e) << endl;*/
	if (s == e) {
		cout << arr[s] << endl;
		return;
	}

	int mid = e;
	while (arr[mid] > arr[s] && mid != s)
		mid--;
	get(s + 1, mid);
	get(mid + 1, e);
	cout << arr[s] << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (cin >> arr[n++]);
	n--;

	get(0, n - 1);
	
	return 0;
}