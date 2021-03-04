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

string str;

int isPalin(int l, int r, bool used) {
	int result = 1;
	for (int i = 0; i < (r - l + 1) / 2; ++i) {
		if (str[l + i] == str[r - i])
			continue;

		if (used) {
			result = 3;
			break;
		}
		result = min(isPalin(l + i + 1, r - i, true), isPalin(l + i, r - i - 1, true));
		break;
	}
	return result == 1 ? result + used : result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> str;

		cout << isPalin(0, str.length() - 1, false) - 1 << endl;
	}

	return 0;
}