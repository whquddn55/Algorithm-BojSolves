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

#define MAX_N 5

int n, a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> a >> b;
	int cnt = 0;
	while (a != b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		cnt++;
	}
	cout << cnt << endl;
	

	return 0;
}
