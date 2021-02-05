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

#define MAX_N 200005

int yPos[MAX_N];
pair<pii, int> arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		cin >> yPos[i];
	}

	for (int i = 0; i < m; ++i) {
		int f, t, cost;
		cin >> f >> t >> cost;
		f--;
		t--;
		if (yPos[f] > yPos[t])
			swap(f, t);
		arr[i] = pair<pii, int>(pii(yPos[f], yPos[t]), cost);
	}
	sort(arr, arr + m);
	sort(yPos, yPos + n);
	

	ll sum = 0;
	ll result = 0;
	int index = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < n; ++i) {
		int hereY = yPos[i];
		while (index < m && hereY == arr[index].first.first) {
			sum += arr[index].second;
			pq.emplace(arr[index].first.second, arr[index].second);
			index++;
		}
		result = max(result, sum);
		while (pq.size() && hereY == pq.top().first) {
			sum -= pq.top().second;
			pq.pop();
		}
	}

	cout << result << endl;
	

	return 0;
}