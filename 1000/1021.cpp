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

int n, m;
int arr[MAX_N];
set<int> s;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) 
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
		s.insert(i);

	auto here = s.begin();
	for (int i = 0; i < m; i++) {
		auto it = s.lower_bound(arr[i]);
		auto temp = here;
		int dist1 = 0;
		while (here != it) {
			dist1++;
			here++;
			if (here == s.end())
				here = s.begin();
		}
		here = temp;
		int dist2 = 0;
		while (here != it) {
			dist2++;
			if (here == s.begin())
				here = s.end();
			here--;
		}
		ans += min(dist1, dist2);
		here++;
		if (here == s.end())
			here = s.begin();
		s.erase(arr[i]);
	}
	cout << ans << endl;

	return 0;
}
