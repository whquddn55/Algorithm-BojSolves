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
#define MAX_N 200005
#define MOD 9901

int n, q;
int arr[MAX_N];
int dp[MAX_N][20];

int getDp(int idx1, int idx2) {
	if (idx2 == 1)
		return arr[idx1];
	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;
	
	return ret = getDp(getDp(idx1, idx2 - 1), idx2 - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	
	memset(dp, -1, sizeof(dp));

	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		int current = b;
		int t = 1;
		while (a) {
			if (a & 1) 
				current = getDp(current, t);
			
			a >>= 1;
			++t;
		}
		cout << current << endl;
	}
	
    return 0;
}