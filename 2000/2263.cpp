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

#define MAX_N 100001

int n;
int pos[MAX_N];
int arr[MAX_N];

void get(int s, int e, int cnt) {
	if (s > e)
		return;
	int realS = s - cnt;
	int realE = e - cnt;
	cout << arr[realE] << ' ';
	if (s == e)
		return;

	int nextPos = pos[arr[realE]];
	get(s, nextPos - 1, cnt);
	get(nextPos + 1, e, cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		pos[t] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	get(0, n - 1, 0);
	
	return 0;
}