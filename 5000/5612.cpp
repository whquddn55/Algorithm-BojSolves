#include <bits/stdc++.h>
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

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 201

int n, m;

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	ans = m;
	while (n--) {
		int a, b;
		cin >> a >> b;
		m += (a - b);
		if (m < 0) {
			cout << 0 << endl;
			return 0;
		}
		ans = max(ans, m);
	}
	cout << ans << endl;
	
	return 0;
}