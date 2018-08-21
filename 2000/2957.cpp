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

#define MAX_N 300000

int n;
int value[MAX_N];
ll cnt = 0;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		t--;

		if (s.empty()) 
			s.insert(t);
		else {
			auto it = s.lower_bound(t);
			if (it == s.begin())
				cnt += value[t] = value[*it] + 1;
			else if (it == s.end())
				cnt += value[t] = value[*--it] + 1;
			else
				cnt += value[t] = max(value[*--it], value[*it]) + 1;
			s.insert(t);
		}

		cout << cnt << endl;
	}
	
	return 0;
}