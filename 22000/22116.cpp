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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 1005
#define MOD 1000000007
#define MOD2 1000000009

int n;
int arr[MAX_N][MAX_N];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool decide(int diff) {
    bool visited[MAX_N][MAX_N] = {0, };
    queue<pii> q;
    q.emplace(0, 0);
    visited[0][0] = true;

    while(q.size()) {
        int hereY = q.front().first;
        int hereX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = hereY + dy[i];
            int nextX = hereX + dx[i];

            if (nextY >= n || nextY < 0 || nextX >= n || nextX < 0)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (abs(arr[hereY][hereX] - arr[nextY][nextX]) > diff)
                continue;
            
            if (nextY == n - 1 && nextX == n - 1)
                return true;
            q.emplace(nextY, nextX);
            visited[nextY][nextX] = true;
        }
    }
    return false;
}

int pSearch(int initL, int initR) {
    int l = initL, r = initR;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (decide(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin >> n;
    int minV = INF, maxV = -INF;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            minV = min(minV, i && j ? min(abs(arr[i][j] - arr[i][j - 1]), abs(arr[i][j] - arr[i - 1][j])) : 0);
            maxV = max(maxV, i && j ? max(abs(arr[i][j] - arr[i][j - 1]), abs(arr[i][j] - arr[i - 1][j])) : 0);
        }
    cout << pSearch(minV, maxV) << endl;

    return 0;
}
