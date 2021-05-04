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

#define MAX_N 101
#define MAX_K 100001

int n, k;
pii arr[MAX_N];
int prv[MAX_K];
int dp[MAX_K];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    dp[arr[0].first] = arr[0].second; 
    prv[arr[0].first] = arr[0].second;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[j] = prv[j];
            if (j >= arr[i].first)
                dp[j] = max(dp[j], prv[j - arr[i].first] + arr[i].second);
        }
        for (int j = 0; j <= k; ++j)
            prv[j] = dp[j];
    }
    int result = 0;
    for (int i = 0; i <= k; ++i)
        result = max(result, dp[i]);
    cout << result << endl;

	return 0;
}
