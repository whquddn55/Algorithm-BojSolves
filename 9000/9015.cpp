#include <bits/stdc++.h>
#include <unordered_set>
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

#define MAX_N 150

struct pair_hash {
	inline std::size_t operator()(const pii & v) const {
		return v.first * 31 + v.second;
	}
};

int n;
unordered_set<pii, pair_hash> s;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		s.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			pii t;
			cin >> t;
			s.emplace(t);
		}
		
		ll ans = 0;
		for (auto it1 = s.begin(); it1 != s.end(); ++it1) {
			pii e1 = *it1;
			auto it2 = it1;
			it2++;
			for (; it2 != s.end(); ++it2) {
				pii e2 = *it2;
				ll dx = e2.first - e1.first; // 1
				ll dy = e2.second - e1.second; // 5
				if (dx * dx + dy * dy < ans)
					continue;

				if ((s.count({ e1.first + dy, e1.second - dx }) && s.count({ e2.first + dy, e2.second - dx })) || (s.count({ e1.first - dy, e1.second + dx }) && s.count({ e2.first - dy, e2.second + dx })))
					ans = max(ans, dx * dx + dy * dy);
			}
		}
		cout << ans << endl;
	}

	return 0;
}