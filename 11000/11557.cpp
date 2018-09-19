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

#define MAX_N 100000

int n;
int maxValue = 0;
string ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		maxValue = 0;
		ans.clear();

		cin >> n;
		while (n--) {
			int value;
			string str;
			cin >> str >> value;
			if (maxValue < value) {
				maxValue = value;
				ans = str;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}