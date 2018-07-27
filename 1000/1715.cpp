#include <bits/stdc++.h>
#include <unordered_map>
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

#define MAX_N 100001

int n;
int ans = 0;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		pq.emplace(t);
	}

	while (pq.size() != 1) {
		int v1 = pq.top();
		pq.pop();
		int v2 = pq.top();
		pq.pop();

		ans += (v1 + v2);
		pq.emplace(v1 + v2);
	}
	cout << ans << endl;

	return 0;
}
