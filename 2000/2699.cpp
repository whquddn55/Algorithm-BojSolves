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

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
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
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> point[i].first >> point[i].second;
		vector<pii> result = getConvexHull();
		sort(result.begin(), result.end(), [](pii& a, pii& b)->bool {
			if (a.second == b.second)
				return a.first < b.first;
			return a.second > b.second;
		});
		sort(result.begin() + 1, result.end(), [&result](pii& a, pii& b)->bool {
			int value = ccw(result.front(), a, b);
			if (value != 0)
				return value < 0;
			return a < b;
		});

		cout << result.size() << endl;
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << endl;
	}

	return 0;
}