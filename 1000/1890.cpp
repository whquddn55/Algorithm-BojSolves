#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

long long dp[MAXSIZE][MAXSIZE]; // (0, 0)에서 (j, i)까지 갈 수 있는 경로의 수
vector<vector<int> > board;

int n;

long long get(const int y, const int x) {
    // base case
    if (y == n - 1 && x == n - 1)
        return 1;
    if (y >= n || x >= n || x < 0 || y < 0)
        return 0;

    long long& ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 0;
    ret += get(y + board[y][x], x) + get(y, x + board[y][x]);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    board.resize(n);

    for (int i = 0; i < n; i++) {
        board[i].resize(n);
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    memset(dp, -1, sizeof(dp));

    cout << get(0, 0) << endl;

    return 0;
}
