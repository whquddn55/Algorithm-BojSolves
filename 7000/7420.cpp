#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100000

int n, l;
pii point[MAX_N];

int ccw(pii a, pii b, pii c) {
	ll value = (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
	if (value == 0)
		return 0; // 일직선
	return value > 0 ? 1 : -1; // 1 : 반 시계 방향 -1 : 시계 방향
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

double dist(pii& a, pii& b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> point[i].first >> point[i].second;

	vector<pii> result = getConvexHull();

	double ans = 0;
	for (int i = 0; i < result.size(); i++) 
		ans += dist(result[i], result[(i + 1) % result.size()]);

	cout << floor(ans + 0.5 + 2 * M_PI * l) << endl;

	return 0;
}