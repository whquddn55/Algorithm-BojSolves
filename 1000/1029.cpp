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
#define MOD 10007

int n;
char arr[MAX_N][MAX_N];
int dp[2 << MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            arr[i][j] -= '0';
        }
    
    for (int i = 0; i < (2 << MAX_N); ++i)
        fill(dp[i], dp[i] + MAX_N, INF);

    dp[1][0] = 0;
    for (int i = 2; i < (2 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) == 0)
                continue;

            vector<int> visited;
            int temp = i;
            int cnt = 0;
            while(temp) {
                if (temp & 1) {
                    if (cnt != j)
                        visited.push_back(cnt);
                }
                temp >>= 1;
                ++cnt;
            }

            for (int prv : visited) {
                if (dp[i ^ (1 << j)][prv] <= arr[prv][j])
                    dp[i][j] = min(dp[i][j], (int)arr[prv][j]);
            }
        }
    }

    int result = 0;
    for (int i = 2; i < (2 << n); ++i) 
        for (int j = 0; j < n; ++j)
            if (dp[i][j] != INF) {
                int temp = i;
                int cnt = 0;
                while(temp) {
                    if (temp & 1)
                        ++cnt;
                    temp >>= 1;
                }
                result = max(result, cnt);
            }
    cout << result << endl;

	return 0;
}