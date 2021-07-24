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
#define MOD 1000000007

int n, m, k;
int f, t;
vector<pii> adj[MAX_N];

int dist[MAX_N][MAX_N];
bool inQ[MAX_N][MAX_N];
queue<pii> q;

void spfa() {
	for (int i = 0; i < MAX_N; ++i)
		for (int j = 0; j < MAX_N; ++j)
			dist[i][j] = INF;
	q.emplace(f, 0);
	inQ[f][0] = true;
	dist[f][0] = 0;

	while(q.size()) {
		int here = q.front().first;
		int hereLen = q.front().second;
		q.pop();

		inQ[here][hereLen] = false;

		for (auto e : adj[here]) {
			int next = e.first;
			int nextCost = e.second;

			if (dist[here][hereLen] + nextCost < dist[next][hereLen + 1]) {
				dist[next][hereLen + 1] = dist[here][hereLen] + nextCost;
				if (!inQ[next][hereLen + 1] && hereLen + 1 < n) {
					q.emplace(next, hereLen + 1);
					inQ[next][hereLen + 1] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> m >> k;
	cin >> f >> t;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	spfa();
	int result = INF;
	for (int i = 0; i < n; ++i) 
		result = min(result, dist[t][i]);
	
	cout << result << endl;

	int sum = 0;
	while (k--)  {
		int c;
		cin >> c;
		sum += c;
		
		result = INF;
		for (int i = 0; i < n; ++i)
			result = min(result, dist[t][i] + sum * i);
		cout << result << endl;
	}
	

	return 0;
}
