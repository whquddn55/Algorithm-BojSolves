#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 801

int n, e;
ll dist[MAX_SIZE][MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	fill(&dist[0][0], &dist[0][0] + MAX_SIZE * MAX_SIZE, INF);
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		dist[s][t] = dist[t][s] = c;
	}

	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int via1, via2;
	cin >> via1 >> via2;
	ll ans = min(dist[1][via1] + dist[via1][via2] + dist[via2][n], dist[1][via2] + dist[via2][via1] + dist[via1][n]);
	cout << (ans >= INF ? -1 : ans)<< endl;

	return 0;
}
