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

int n;
pii arr[MAX_N];
set<int> seat;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int maxSize = 0;
int ans[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		seat.insert(i);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		while (pq.size() && pq.top().first <= arr[i].first) {
			seat.insert(pq.top().second);
			pq.pop();
		}
		int seatNum = *seat.begin();
		seat.erase(seatNum);
		ans[seatNum]++;
		pq.emplace(arr[i].second, seatNum);
		maxSize = max(maxSize, (int)pq.size());
	}
	cout << maxSize << endl;
	for (int i = 0; i < maxSize; i++)
		cout << ans[i] << ' ';
	cout << endl;

	return 0;
}