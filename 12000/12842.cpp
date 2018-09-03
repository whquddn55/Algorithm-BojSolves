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

#define MAX_N 100000

int n, s, m;
int remain;
int arr[MAX_N];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> s;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> arr[i];
	remain = n - s;

	for (int i = 0; i < m; i++)
		pq.emplace(0, i);
	remain--;
	while (remain--) {
		int time = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		pq.emplace(time + arr[idx], idx);
	}
	cout << pq.top().second + 1 << endl;

	return 0;
}