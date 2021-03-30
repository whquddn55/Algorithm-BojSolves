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

#define INF (INT_MAX / 2)

#define MAX_N 1005

int n, m, k;
char arr[MAX_N][MAX_N];
pii f, t;

queue<pii> q;
pii visited[MAX_N][MAX_N];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
int inQ[2];
int bfs() {
    q.emplace(f);
    q.emplace(t);
    visited[f.first][f.second] = {1, 0};
    visited[t.first][t.second] = {2, 0};
    inQ[0] = inQ[1] = 1;

    while(q.size()) {
        int hereY = q.front().first;
        int hereX = q.front().second;
        q.pop();

        inQ[visited[hereY][hereX].first - 1]--;

        for (int direction = 0; direction < 4; ++direction) {
            for (int j = 0; j <= k; ++j) {
                int nextY = hereY + dy[direction] * j;
                int nextX = hereX + dx[direction] * j;

                // boundary check
                if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)  
                    continue;

                if (visited[nextY][nextX].first != 0 && 
                    visited[nextY][nextX].first != visited[hereY][hereX].first) {
                    return visited[nextY][nextX].second + visited[hereY][hereX].second + 1;
                } 

                if (visited[nextY][nextX].first == visited[hereY][hereX].first)
                    continue;

                if (arr[nextY][nextX] == '#')
                    break;

                q.emplace(nextY, nextX);
                visited[nextY][nextX] = {visited[hereY][hereX].first, visited[hereY][hereX].second + 1};
                inQ[visited[hereY][hereX].first - 1]++;
            }
        }

        if (inQ[0] == 0 || inQ[1] == 0)
            return -1;
    }
    return -1;
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            cin >> arr[i][j];
        
    cin >> f >> t;
    --f.first;
    --f.second;
    --t.first;
    --t.second;
    
    cout << bfs() << endl;

	return 0;
}