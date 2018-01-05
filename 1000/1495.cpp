#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1001

bool dp[101][MAXSIZE]; // i번째 곡에서 볼륨 j를 연주할 수 있는가
int n, s, m;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> s >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (s - v[0] >= 0)
        dp[0][s - v[0]] = true;
    if (s + v[0] <= m)
        dp[0][s + v[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j]) {
                if (j - v[i] >= 0)
                    dp[i][j - v[i]] = true;
                if (j + v[i] <= m)
                    dp[i][j + v[i]] = true;
            }
        }
    }

    int result = -1;
    for (int i = m; i >= 0; i--) {
        if (dp[n - 1][i]) {
            result = i;
            break;
        }
    }
    cout << result << endl;


    return 0;
}
