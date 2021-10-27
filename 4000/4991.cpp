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
#define MAX_N 23

int w, h;
char arr[MAX_N][MAX_N];
int dist[405][405];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void bfs(int sy, int sx) {
    queue<pair<pii, int>> q;
    q.emplace(pii(sy, sx), 0);
    dist[sy * w + sx][sy * w + sx] = 0;
    while(q.size()) {
        int hy = q.front().first.first;
        int hx = q.front().first.second;
        int step = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = hy + dy[i];
            int nx = hx + dx[i];

            if (ny >= h || ny < 0 || nx >= w || nx < 0)
                continue;
            if (dist[sy * w + sx][ny * w + nx] != -1)
                continue;
            if (arr[ny][nx] == 'x')
                continue;
            q.emplace(pii(ny, nx), step + 1);
            dist[sy * w + sx][ny * w + nx] = step + 1;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    while(true) {
        memset(dist, -1, sizeof(dist));

        cin >> w >> h;
        if (!w && !h)
            break;
        
        vector<pii> s;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] == 'o' || arr[i][j] == '*') 
                    s.emplace_back(i, j);
            }

        for (int i = 0; i < s.size(); ++i) {
            if (arr[s[i].first][s[i].second] == 'o')
                swap(s[i], s[s.size() - 1]);
        }
        
        for (auto& p : s) {
            bfs(p.first, p.second);
        }

        pii t = s.back();
        s.pop_back();
        vector<int> permu;
        int ans = INF;
        for (int i = 0; i < s.size(); ++i)
            permu.emplace_back(i);

        do {
            int sum = dist[s[permu.back()].first * w + s[permu.back()].second][t.first * w + t.second];
            if (dist[s[permu.back()].first * w + s[permu.back()].second][t.first * w + t.second] == -1)
                sum = INF;

            for (int i = 0; i < s.size() - 1; ++i) {
                int index = permu[i];
                int nindex = permu[i + 1];
                sum += dist[s[index].first * w + s[index].second][s[nindex].first * w + s[nindex].second];
                if (dist[s[index].first * w + s[index].second][s[nindex].first * w + s[nindex].second] == -1) {
                    sum = INF;
                    break;
                }
            }
            ans = min(ans, sum);
        } while (next_permutation(all(permu)));
        cout << (ans == INF ? - 1: ans) << endl;
    }
    
    return 0;
}
