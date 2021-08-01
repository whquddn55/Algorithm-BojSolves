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
#define MAX_N 105
#define MOD 1000000007

int n, m;
pii w[MAX_N], b[MAX_N];

int ccw(const pii& a, const pii& b, const pii& c) {
	ll value = (ll)a.first * b.second + (ll)b.first * c.second + (ll)c.first * a.second;
	value -= (ll)b.first * a.second + (ll)c.first * b.second + (ll)a.first * c.second;
	if (value)
		return value / abs(value);
	else
		return 0;
}

vector<int> getHull(pii arr[], int size) {
	sort(arr, arr + size, [](pii& a, pii& b) -> bool {
		if (a.second != b.second)
			return a.second < b.second;
		else
			return a.first < b.first;
	});

	sort(arr + 1, arr + size, [&](pii& a, pii& b) -> bool {
		int c = ccw(arr[0], a, b);
		if (c == 0)
			return (ll)a.first * a.first + (ll)a.second * a.second < (ll)b.first * b.first + (ll)b.second * b.second;
		return c == 1;
	});

	vector<int> hull;
	hull.push_back(0);
	hull.push_back(1);
	for (int nxt = 2; nxt < size; ++nxt) {
		while(hull.size() >= 2) {
			int second = hull.back();
			hull.pop_back();
			int first = hull.back();
			if (ccw(arr[first], arr[second], arr[nxt]) == 1) {
				hull.push_back(second);
				break;
			}
		}
		hull.push_back(nxt);
	}
	return hull;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> b[i];
		for (int i = 0; i < m; ++i)
			cin >> w[i];

		bool ans = true;
		if (n == 1) {
		} 
		else if (n == 2) {
			int t = ccw(b[0], b[1], w[0]);
			for (int i = 0; i < m; ++i) {
				int c = ccw(b[0], b[1], w[i]);
				if (c * t == -1 || (c == 0 && b[0].first <= w[i].first && w[i].first <= b[1].first))
					ans = false;
			}
		}
		else {
			vector<int> blackHull = getHull(b, n);
			
			for (int i = 0; i < m; ++i) {
				bool check = true;
				for (int j = 0; j < blackHull.size(); ++j) {
					int c = ccw(b[blackHull[j]], b[blackHull[(j + 1) % blackHull.size()]], w[i]);
					if (c == -1)
						check = false;
				}
				if (check)
					ans = false;
			}
		}

		if (m == 1) {
			
		}
		else if (m == 2) {
			int t = ccw(w[0], w[1], b[0]);
			for (int i = 0; i < n; ++i) {
				int c = ccw(w[0], w[1], b[i]);
				if (c * t == -1 || (c == 0 && w[0].first <= b[i].first && b[i].first <= w[1].first))
					ans = false;
			}
		}
		else {
			vector<int> whiteHull = getHull(w, m);
			for (int i = 0; i < n; ++i) {
				bool check = true;
				for (int j = 0; j < whiteHull.size(); ++j) {
					int c = ccw(w[whiteHull[j]], w[whiteHull[(j + 1) % whiteHull.size()]], b[i]);
					if (c == -1)
						check = false;
				}
				if (check)
					ans = false;
			}
		}

		cout << (ans ? "YES" : "NO") << endl;
	}

	

	return 0;
}
