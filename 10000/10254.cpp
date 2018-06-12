#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 200001

int n;
pii point[MAX_N];

ll ans = 0;

pii operator-(pii& a, pii& b) {
	return { a.first - b.first, a.second - b.second };
}

int ccw(pii a, pii b, pii c) {
	ll value = (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
	if (value == 0)
		return 0; // 일직선
	return value > 0 ? 1 : -1; // 1 : 반시계 방향 -1 : 시계 방향
}

vector<pii> getConvexHull() {
	sort(point, point + n);
	sort(point + 1, point + n, [](pii& a, pii& b)->bool {
		int value = ccw(point[0], a, b);
		if (value != 0)
			return value > 0;
		return a < b;
	});

	vector<pii>  st;
	for (int i = 0; i < n; i++) {
		while (st.size() >= 2 && ccw(st[st.size() - 2], st.back(), point[i]) <= 0)
			st.pop_back();
		st.emplace_back(point[i]);
	}
	return st;
}

ll getDist(pii& a, pii& b) {
	return (ll)(b.first - a.first) * (b.first - a.first) + (ll)(b.second - a.second) * (b.second - a.second);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> point[i].first >> point[i].second;
		vector<pii> result = getConvexHull();

		ll maxDist = -1;
		pii p1(0, 0), p2(0, 0);
		for (int i = 0, j = 1; i < n; i++) {
			while (ccw({ 0, 0 }, result[(i + 1) % result.size()] - result[i % result.size()], result[(j + 1) % result.size()] - result[j % result.size()]) > 0)
				j++;

			for (int k = j; k < j + 2; k++)
				if (maxDist < getDist(result[i % result.size()], result[k % result.size()])) {
					maxDist = getDist(result[i % result.size()], result[k % result.size()]);
					p1 = result[i % result.size()];
					p2 = result[k % result.size()];
				}
		}

		cout << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << endl;
	}

	return 0;
}