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

#define MAX_N 20

string a, b;
deque<int> arrA, arrB;
int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		arrA.clear();
		arrB.clear();
		ans = 0;

		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << -1 << endl;
			continue;
		}
		int aCnt = 0;
		for (auto e : a)
			if (e == 'a')
				aCnt++;
		for (auto e : b)
			if (e == 'a')
				aCnt--;
		if (aCnt) {
			cout << -1 << endl;
			continue;
		}

		for (int i = 0; i < a.size(); i++) {
			if (a[i] == 'a')
				arrA.emplace_back(i);
			else
				arrB.emplace_back(i);
		}

		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) {
				if (a[i] == 'a')
					arrA.pop_front();
				else
					arrB.pop_front();
				continue;
			}
			else if (a[i] == 'a') {
				ans += arrB[0] - i;
				swap(a[i], a[arrB[0]]);
				arrB.pop_front();
			}
			else {
				ans += arrA[0] - i;
				swap(a[i], a[arrA[0]]);
				arrA.pop_front();
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}