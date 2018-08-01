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

#define MAX_N 500

int t1, t2;
int n;
pii ans;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		t1 = 267914296;
		t2 = 433494437;
		ans = { INF, INF };

		while (t1 > 0) {
			bool flag = false;
			for (int a2 = 1; a2 * t2 < n; a2++) {
				int t = n - a2 * t2;
				if (t % t1)
					continue;
				if (t / t1 > a2)
					continue;

				if (ans.second > a2 || (ans.second == a2 && ans.first > t / t1)) {
					ans = { t / t1, a2 };
					flag = true;
					break;
				}
			}
			if (flag)
				break;

			int temp = t1;
			t1 = (t2 - t1);
			t2 = temp;
		}

		cout << ans << endl;
	}

	return 0;
}