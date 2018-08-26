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

#define MAX_N 101

int n;
int cnt[MAX_N];
set<int> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		ans.clear();

		for (int i = 1; i <= n; i++)
			ans.insert(i);

		while (true) {
			memset(cnt, 0, sizeof(cnt));
			bool isEnd = true;
			for (auto e1 : ans)
				for (auto e2 : ans)
					if (ans.count(e1 ^ e2)) {
						isEnd = false;
						cnt[e1 ^ e2]++;
					}
			if (isEnd)
				break;

			ans.erase(max_element(cnt, cnt + MAX_N) - cnt);
		}
		cout << ans.size() << endl;
		for (auto e : ans)
			cout << e << ' ';
		cout << endl;
	}

	return 0;
}