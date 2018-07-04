#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 100001

int n, k;
int ans1 = -1, ans2 = 0;
bool visited[MAX_N];

void bfs() {
	queue<pii> q;
	q.emplace(n, 0);
	
	while (!q.empty()) {
		int here = q.front().first;
		int time = q.front().second;
		q.pop();

		visited[here] = true;

		if (here == k && ans1 == -1) {
			ans1 = time;
			ans2++;
			continue;
		}
		if (ans1 != -1) {
			if (time > ans1)
				continue;
			if (here == k) {
				ans2++;
				continue;
			}
		}

		int d[3] = { -1, 1, here };
		for (int i = 0; i < 3; i++) {
			int next = here + d[i];

			if (next >= 0 && next < MAX_N && !visited[next]) 
				q.emplace(next, time + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;
	bfs();

	cout << ans1 << endl << ans2 << endl;

	return 0;
}
