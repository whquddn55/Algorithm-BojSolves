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

#define MAX_N 31

int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cnt = 0;
		for (int j = 0; j < 4; j++) {
			int t;
			cin >> t;
			cnt += t;
		}
		switch (cnt) {
		case 0 :
			cout << 'D' << endl;
			break;
		case 1:
			cout << 'C' << endl;
			break;
		case 2:
			cout << 'B' << endl;
			break;
		case 3:
			cout << 'A' << endl;
			break;
		case 4:
			cout << 'E' << endl;
			break;
		}
	}
	return 0;
}