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
 
#define MAX_N 1005

int n, m;
string s1, s2;

int dp[MAX_N][MAX_N];

pii track(int x, int y) {
    if (dp[x][y] == 0) 
        return {INF, INF};
    
    if ((s1[x - 1] == s2[y - 1]) && (dp[x][y] == dp[x - 1][y - 1] + 3))
        return min(pii{x, y}, track(x - 1, y - 1));
    else {
        if (dp[x][y] == dp[x - 1][y] - 2)
            return min(pii{x, y}, track(x - 1, y));
        else if (dp[x][y] == dp[x][y - 1] - 2)
            return min(pii{x, y}, track(x, y - 1));
        else
            return min(pii{x, y}, track(x - 1, y - 1));
    }
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
 
    cin >> n >> s1 >> m >> s2;
	
	int maxValue = 0;
	pii maxIndex;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int off = s1[i - 1] == s2[j - 1] ? 3 : -2;
            dp[i][j] = max({dp[i - 1][j - 1] + off, dp[i - 1][j] - 2, dp[i][j - 1] - 2, 0});
            if (maxValue < dp[i][j]) {
            	maxValue = dp[i][j];
            	maxIndex = {i, j};
            }
        }

    cout << maxValue << endl;
    pii resultIndex = track(maxIndex.first, maxIndex.second);
    cout << s1.substr(resultIndex.first - 1, maxIndex.first - resultIndex.first + 1) << endl;
    cout << s2.substr(resultIndex.second - 1, maxIndex.second - resultIndex.second + 1) << endl;
 
	return 0;
}