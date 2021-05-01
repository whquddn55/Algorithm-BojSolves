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

#define MAX_N 1505

int r, c;
int psumB[MAX_N][MAX_N];
int psumA[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> r>> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            char c;
            cin >> c;
            int value;
            cin >> value;
            if (c == 'A') {
                psumB[i][j] = psumB[i - 1][j];
                psumA[i][j] = psumA[i - 1][j]+ value;
            }
            else {
                psumB[i][j] = psumB[i - 1][j] + value;
                psumA[i][j] = psumA[i - 1][j];
            }
        }
    
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            if (j == 1 && i != 1)
                dp[i][j] = dp[i - 1][j] - (psumA[i][j] - psumA[i - 1][j]);
            else
                dp[i][j] = max({
                    dp[i][j - 1] + psumB[i - 1][j] + psumA[r][j] - psumA[i][j], 
                    dp[i - 1][j - 1] + psumB[i - 1][j] + psumA[r][j] - psumA[i][j],
                    dp[i - 1][j] - (psumA[i][j] - psumA[i - 1][j])
                });
            
        }
    cout << dp[r][c] << endl;

	return 0;
}
