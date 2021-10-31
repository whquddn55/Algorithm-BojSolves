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
#define MAX_N 20

int n, m, c;
string arr[MAX_N];

int dy[] = {-1, 0, 1, 0, 0};
int dx[] = {0, 1, 0, -1, 0};
bool visited[1<<25 - 1];

void pickAndPush(queue<pii>& q, vector<pii>& temp, const vector<pii>& origin, int cost, int depth) {
    if (depth == c) {
        int offset = 0;
        int nxt = 0;
        for (int i = 0; i < c; ++i) {
            nxt |= temp[i].first << (offset + 4);
            nxt |= temp[i].second << offset;
            offset += 8;
            
        }
        if (visited[nxt])
            return;

        int cnt = 0;
        for (int i = 0; i < c; ++i)
            for (int j = i + 1; j < c; ++j)
                if ((temp[i] == origin[j]) && (origin[i] == temp[j])) 
                    ++cnt;
        if (cnt >= 1)
            return;
        cnt = 0; 
        for (int i = 0; i < c; ++i)
            for (int j = i + 1; j < c; ++j)
                if (temp[i] == temp[j]) 
                    ++cnt;
        if (cnt >= 1)
            return;

        q.emplace(nxt, cost + 1);
        visited[nxt] = true;
        return;
    }

    int ty = temp[depth].first;
    int tx = temp[depth].second;
    for (int i = 0; i < 5; ++i) {
        int ny = ty + dy[i];
        int nx = tx + dx[i];

        if (ny >= n || ny < 0 || nx >= m || nx < 0)
            continue;
        if (arr[ny][nx] == '#')
            continue;
        temp[depth].first = ny;
        temp[depth].second = nx;
        pickAndPush(q, temp, origin, cost, depth + 1);
    }
}

int bfs() {
    queue<pii> q;
    int init = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 'a')
                init |= ((i << 4) + j);
            else if (arr[i][j] == 'b')
                init |= ((i << 12) + (j << 8));
            else if (arr[i][j] == 'c')
                init |= ((i << 20) + (j << 16));
        }
    q.emplace(init, 0);
    visited[init] = true;

    while(q.size()) {
        int here = q.front().first;
        int cost = q.front().second;
        q.pop();

        int ay = (here & 0x000000f0) >> 4;
        int ax = (here & 0x0000000f);
        int by = (here & 0x0000f000) >> 12;
        int bx = (here & 0x00000f00) >> 8;
        int cy = (here & 0x00f00000) >> 20;
        int cx = (here & 0x000f0000) >> 16;

        if (arr[ay][ax] == 'A' && (c <= 1 || arr[by][bx] == 'B') && (c <= 2 || arr[cy][cx] == 'C'))
            return cost;

        vector<pii> temp;
        if (c >= 1)
            temp.emplace_back(ay, ax);
        if (c >= 2)
            temp.emplace_back(by, bx);
        if (c >= 3)
            temp.emplace_back(cy, cx);
        vector<pii> origin = temp;
        pickAndPush(q, temp, origin, cost, 0);
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    while(true) {
        memset(visited, 0, sizeof(visited));

        cin >> m >> n >> c;
        getline(cin, arr[0]);
        if (!n && !m && !c)
            break;
        for (int i = 0; i < n; ++i)
            getline(cin, arr[i]);
        

        cout << bfs() << endl;
    }
    
    return 0;
}
