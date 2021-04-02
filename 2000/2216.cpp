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
 
#define MAX_N 3005

int a, b, c;
string s1, s2;

int dp[MAX_N][MAX_N];
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
 
    cin >> a >> b >> c >> s1 >> s2;

    for (int i = 0; i <= s1.size(); ++i)
        dp[i][0] = b * i;
    
    for (int i = 0; i <= s2.size(); ++i)
        dp[0][i] = b * i;

    for (int i = 1; i <= s1.size(); ++i)
        for (int j = 1; j <= s2.size(); ++j) {
            int off = s1[i - 1] == s2[j - 1] ? a : c;
            dp[i][j] = max({dp[i - 1][j - 1] + off, dp[i - 1][j] + b, dp[i][j - 1] + b});
        }

    cout << dp[s1.size()][s2.size()] << endl;
 
	return 0;
}