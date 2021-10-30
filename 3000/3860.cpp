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

#define all(x) (x).begin(), (x).end()
#define INF (INT_MAX / 2)
#define MAX_N 40

int w, h, g, e;
bool arr[MAX_N][MAX_N];
pair<pii, pii> brr[MAX_N][MAX_N];

int dist[MAX_N][MAX_N];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool spfa(int sy, int sx) {
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            dist[i][j] = INF;
    bool inQ[MAX_N][MAX_N] = { false, };
    int cycle[MAX_N][MAX_N] = { 0, };
    queue<pii> q;
    q.emplace(sy, sx);

    dist[sy][sx] = 0;
    inQ[sy][sx] = true;
    cycle[sy][sx]++;

    while (!q.empty()) {
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();
        inQ[hy][hx] = false;

        if (hy == h - 1 && hx == w - 1) 
            continue;

        if (brr[hy][hx].second.second) {
            int ny = brr[hy][hx].first.first;
            int nx = brr[hy][hx].first.second;
            if (dist[ny][nx] > dist[hy][hx] + brr[hy][hx].second.first) {
                dist[ny][nx] = dist[hy][hx] + brr[hy][hx].second.first;
                if (!inQ[ny][nx]) {
                    cycle[ny][nx]++;
                    
                    q.emplace(ny, nx);
                    inQ[ny][nx] = true;
                }
            }
            if (cycle[ny][nx] >= h * w) {
                return true;
            }
        }
        else {
            for (int i = 0; i < 4; ++i) {
                int ny = hy + dy[i];
                int nx = hx + dx[i];

                if (ny >= h || ny < 0 || nx >= w || nx < 0)
                    continue; 
                if (arr[ny][nx])
                    continue;

                if (dist[ny][nx] > dist[hy][hx] + 1) {
                    dist[ny][nx] = dist[hy][hx] + 1;
                    if (!inQ[ny][nx]) {
                        cycle[ny][nx]++;
                        
                        q.emplace(ny, nx);
                        inQ[ny][nx] = true;
                    }
                }
                if (cycle[ny][nx] >= h * w) {
                    return true;
                }
                
            }
        }
        
    
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    while (true){
        memset(arr, 0, sizeof(arr));
        memset(brr, 0, sizeof(brr));

        cin >> w >> h;
        if (!w && !h)
            break;
        cin >> g;
        for (int i = 0; i < g; ++i){
            int x, y;
            cin >> x >> y;
            arr[y][x] = true;
        }
        cin >> e;
        for (int i = 0; i < e; ++i) {
            int x, y;
            cin >> x >> y;
            cin >> brr[y][x].first.second >> brr[y][x].first.first >> brr[y][x].second.first;
            brr[y][x].second.second = true;
        }

        bool cycle = spfa(0, 0);
        if (cycle)
            cout << "Never" << endl;
        else if (dist[h - 1][w - 1] == INF)
            cout << "Impossible" << endl;
        else
            cout <<dist[h - 1][w - 1] << endl;
    }
    
    return 0;
}
