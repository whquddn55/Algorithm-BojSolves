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

#define MAX_N 50000

int m;
pii arr[MAX_N];
int maxValue = 0;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc;
	cin >> tc;
	for (int ntc = 1; ntc <= tc; ntc++) {
		cout << "Scenario #" << ntc << ":"<< endl; 
		ans = 0;
		maxValue = 0;

		cin >> m;
		for (int i = 0; i < m; i++) {
			int day;
			cin >> day;
			cin >> arr[i];
			day--;
			arr[i].first += day * 2400;
			arr[i].second += day * 2400;
		}

		for (int i = 0; i < m; i++)
			pq.emplace(arr[i].second, i);
		while (pq.size()) {
			pii value = pq.top();
			pq.pop();

			if (arr[value.second].first < maxValue)
				continue;

			maxValue = max(maxValue, value.first);
			ans++;
		}

		cout << ans << endl << endl;
	}

	return 0;
}