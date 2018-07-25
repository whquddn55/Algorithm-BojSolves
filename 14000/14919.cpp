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

#define MAX_M 1001

int m;
int cnt[MAX_M];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> m;
	double t;
	while (cin >> t) {
		t *= m;
		int integer = (int)(t + 0.0000001);
		cnt[integer]++;
	}
	for (int i = 0; i < m; i++)
		cout << cnt[i] << ' ';
	cout << endl;

	return 0;
}
