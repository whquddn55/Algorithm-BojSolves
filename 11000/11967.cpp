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
#define MAX_N 105
#define MOD 1000000007

int n, m;
vector<pii> adj[MAX_N][MAX_N];

queue<pii> q;
bool visited[MAX_N][MAX_N];
bool lighted[MAX_N][MAX_N];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int bfs(int sX, int sY) {
	q.emplace(sX, sY);
	visited[sX][sY] = true;
	lighted[sX][sY] = true;

	int res = 1;
	while(q.size()) {
		pii here = q.front();
		q.pop();

		
		for (auto next : adj[here.first][here.second]) {
			if (lighted[next.first][next.second] == false) {
				lighted[next.first][next.second] = true;
				++res;

				if (!visited[next.first][next.second]) {
					bool canPush = false;
					for (int i = 0; i < 4; ++i) {
						int ny = next.first + dy[i];
						int nx = next.second + dx[i];

						if (ny >= n || ny < 0 || nx >= n || nx < 0)
							continue;
						if (visited[ny][nx]) {
							canPush = true;
							break;
						}
					}
					if (canPush) {
						q.emplace(next.first, next.second);
						visited[next.first][next.second] = true;
					}
				}
			}
		}
		for (int i = 0; i < 4; ++i) {
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];

			if (ny >= n || ny < 0 || nx >= n || nx < 0)
					continue;
			if (visited[ny][nx] || !lighted[ny][nx])
				continue;

			q.emplace(ny, nx);
			visited[ny][nx] = true;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		pii f, t;
		cin >> f >> t;
		f.first--;
		f.second--;
		t.first--;
		t.second--;

		adj[f.first][f.second].push_back(t);
		
	}

	cout << bfs(0, 0) << endl;
	return 0;
}