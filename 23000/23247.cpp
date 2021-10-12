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

#define MAX_N 305

int n, m;
int arr[MAX_N][MAX_N];
int psum[MAX_N][MAX_N];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= m; ++j){
			cin >> arr[i][j];
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + arr[i][j];
		}
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int y = max(1, i - 10); y <= i; ++y)
				for (int x = max(1, j - 10); x <= j; ++x)
					if (psum[i][j] - psum[y - 1][j] - psum[i][x - 1] + psum[y - 1][x - 1] == 10)
						++ans;
		}
	}
	cout << ans << endl;
}