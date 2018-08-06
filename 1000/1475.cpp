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
#define MAX_N 15

string str;
int cnt[10];
int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> str;
	for (auto e : str)
		cnt[e - '0']++;

	for (int i = 0; i < 10; i++)
		ans = max(ans, (i == 6 || i == 9) ? (cnt[6] + cnt[9] + 1) / 2 : cnt[i]);
	cout << ans << endl;

	return 0;
}
