#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 55
#define MOD 1'000'000'007

struct Data {
    int mass = 0, speed = 0, dir = 0;
    int cnt = 0;
    bool allOdd = true, allEven = true;
};

int n, m, tc;
Data arr[MAX_N][MAX_N];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int getModded(int v) {
    while(v < 0)
        v += n;
    return v % n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> tc;
    for (int i = 0; i < m; ++i) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        --a; --b;
        arr[a][b].mass = c;
        arr[a][b].speed = d;
        arr[a][b].dir = e;
        arr[a][b].cnt = 1;
    }

    while (tc--) {
        Data temp[MAX_N][MAX_N];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                temp[i][j] = Data();
                
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (arr[i][j].cnt > 1) {
                    bool offset = !arr[i][j].allOdd && !arr[i][j].allEven;
                    for (int k = offset; k < 8; k += 2) {
                        if (arr[i][j].mass / 5 == 0)
                            continue;
                        int ny = getModded(i + dy[k] * (arr[i][j].speed / arr[i][j].cnt)); 
                        int nx = getModded(j + dx[k] * (arr[i][j].speed / arr[i][j].cnt));
                        temp[ny][nx].mass += arr[i][j].mass / 5;
                        temp[ny][nx].speed += arr[i][j].speed / arr[i][j].cnt;
                        temp[ny][nx].dir = k;
                        temp[ny][nx].cnt++;
                        temp[ny][nx].allOdd &= k % 2;
                        temp[ny][nx].allEven &= !(k % 2);
                    }
                }
                else if (arr[i][j].cnt == 1){
                    int ny = getModded(i + dy[arr[i][j].dir] * arr[i][j].speed); 
                    int nx = getModded(j + dx[arr[i][j].dir] * arr[i][j].speed); 
                    temp[ny][nx].mass += arr[i][j].mass;
                    temp[ny][nx].speed += arr[i][j].speed;
                    temp[ny][nx].dir = arr[i][j].dir;
                    temp[ny][nx].cnt++;
                    temp[ny][nx].allOdd &= arr[i][j].dir % 2;
                    temp[ny][nx].allEven &= !(arr[i][j].dir % 2);
                }
            }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                arr[i][j] = temp[i][j];
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (arr[i][j].cnt > 1) {
                arr[i][j].mass /= 5;
                arr[i][j].mass *= 4;
            }
            ans += arr[i][j].mass;
        }
    cout << ans << endl;

    return 0;
}
