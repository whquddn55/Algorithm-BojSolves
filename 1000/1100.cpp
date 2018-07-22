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

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 50

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			char t;
			cin >> t;
			if ((i + j) % 2 == 0 && t == 'F')
				ans++;
		}
	cout << ans << endl;
	
	return 0;
}
