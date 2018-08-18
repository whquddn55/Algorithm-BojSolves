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

#define INF (LLONG_MAX / 2)

#define MAX_N 100

int n, m;
int arr[MAX_N][MAX_N];
vector<pii> boxPos;

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		boxPos.clear();
		ans = 0;

		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j])
					boxPos.emplace_back(i, j);
			}

		for (auto pi : boxPos) 
			for (int i = pi.first; i < n; i++)
				if (arr[i][pi.second] == 0)
					ans++;
		
		cout << ans << endl;
	}
	
	return 0;
}