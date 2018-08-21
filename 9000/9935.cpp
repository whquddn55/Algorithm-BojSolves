#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 1000000

string s, p;
pii isIn[200];
stack<pii> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> s >> p;
	for (int i = 0; i < p.size(); i++)
		isIn[p[i]] = { true, i };

	for (int i = 0; i < s.size(); i++) {
		auto e = s[i];
		if (isIn[e].first) {
			if (isIn[e].second == 0 || (st.size() && isIn[e].second == isIn[st.top().first].second + 1)) {
				st.emplace(e, i);
				if (isIn[e].second == p.size() - 1) {
					int cnt = p.size();
					while (cnt--) {
						s[st.top().second] = 0;
						st.pop();
					}
				}
			}
			else
				while (st.size())
					st.pop();
		}
		else
			while (st.size())
				st.pop();
	}
	bool printed = false;
	for (auto e : s) 
		if (e) {
			cout << e;
			printed = true;
		}
	if (!printed)
		cout << "FRULA" << endl;
	
	return 0;
}