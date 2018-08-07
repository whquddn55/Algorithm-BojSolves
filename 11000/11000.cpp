#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 200000

int n;
pii arr[MAX_N];
int ans;

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		while (!pq.empty() && pq.top().first <= arr[i].first)
			pq.pop();
		pq.emplace(arr[i].second, arr[i].first);
		ans = max(ans, (int)pq.size());
	}
	cout << ans << endl;

	return 0;
}
