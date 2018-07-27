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

#define MAX_N 1000000

int n;
priority_queue<int, vector<int>, greater<int>> minq;
priority_queue<int> maxq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (maxq.size() > minq.size())
			minq.emplace(t);
		else
			maxq.emplace(t);

		if (maxq.size() && minq.size() && maxq.top() > minq.top()) {
			int v1 = maxq.top(), v2 = minq.top();
			maxq.pop();
			minq.pop();
			minq.emplace(v1);
			maxq.emplace(v2);
		}
		cout << maxq.top() << endl;
	}

	return 0;
}
