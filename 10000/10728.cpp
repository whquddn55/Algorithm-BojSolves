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

#define MAX_N 6

int n;
set<int> s;
set<int> ans;

bool check1(int num) {
	for (auto e1 : s)
		for (auto e2 : s)
			if (e1 != e2 && (e1 ^ e2 ^ num) == 0)
				return false;
	return true;
}

bool check2() {
	for (auto e1 : s)
		for (auto e2 : s)
			for (auto e3 : s)
				if ((e1 ^ e2 ^ e3) == 0)
					return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		s.clear();
		ans.clear();

		cin >> n;
		for (int i = 1; i <= n; i++) {
			if (!check1(i)) {
				s.erase(s.begin());
				s.insert(i);
				while (!check2())
					s.erase(s.begin());
			}
			else
				s.insert(i);
			if (s.size() > ans.size())
				ans = s;
		}
		 cout << ans.size() << endl;
		 for (auto e : ans)
		 cout << e << ' ';
		 cout << endl;
	}

	return 0;
}