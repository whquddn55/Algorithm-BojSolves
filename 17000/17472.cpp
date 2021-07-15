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
#define MAX_N 10
#define MOD 1000000007

int n, m;
int arr[MAX_N][MAX_N];
int cnt = 0;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
void dfs(int hereY, int hereX) {
	arr[hereY][hereX] = cnt;
	for (int i = 0; i < 4; ++i) {
		int nextY = hereY + dy[i];
		int nextX = hereX + dx[i];

		if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= m)
			continue;
		if (arr[nextY][nextX] != -1)
			continue;
		dfs(nextY, nextX);
 	}
}

int adj[MAX_N + 1][MAX_N + 1];
set<int> s;
int prim() {
	int result = 0;
	s.insert(1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 1; i <= cnt; ++i)
		if (adj[1][i])
			pq.emplace(adj[1][i], i);
	while(pq.size()) {
		int nextNode = pq.top().second;
		int edgeCost = pq.top().first;
		pq.pop();

		if (s.find(nextNode) == s.end()) {
			s.insert(nextNode);
			result += edgeCost;
			for (int i = 1; i <= cnt; ++i)
				if (adj[nextNode][i])
					pq.emplace(adj[nextNode][i], i);
		}
	}
	if (s.size() != cnt)
		result = -1;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j])
				arr[i][j] = -1;
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (arr[i][j] == -1) {
				cnt++;
				dfs(i, j);
			}

	for (int i = 1; i <= cnt; ++i)
		for (int j = 1; j <= cnt; ++j)
			adj[i][j] = INF;
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (arr[i][j]) {
				for (int t = 0; t < 4; ++t){
					for (int k = 1; k <= MAX_N; ++k)  {
						int nextY = i + dy[t] * k;
						int nextX = j + dx[t] * k;
						if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= m)
							continue;
						if (arr[nextY][nextX]) {
							if (k >= 3) 
								adj[arr[i][j]][arr[nextY][nextX]] = min(adj[arr[i][j]][arr[nextY][nextX]], k - 1);
							break;
						}
					}
					for (int k = 1; k <= MAX_N; ++k)  {
						int nextY = i - dy[t] * k;
						int nextX = j - dx[t] * k;
						if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= m)
							continue;
						if (arr[nextY][nextX]) {
							if (k >= 3) 
								adj[arr[i][j]][arr[nextY][nextX]] = min(adj[arr[i][j]][arr[nextY][nextX]], k - 1);
							break;
						}
					}
				}
			}

	for (int i = 1; i <= cnt; ++i)
		for (int j = 1; j <= cnt; ++j)
			if (adj[i][j] == INF)
				adj[i][j] = 0;

	cout << prim() << endl;

	return 0;
}
