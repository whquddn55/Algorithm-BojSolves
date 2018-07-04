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

#define MAX_N 11

int a, b;
bool visited[10000];

void bfs() {
	queue<pair<int, string>> q;
	q.emplace(a, "");
	visited[a] = true;

	while (!q.empty()) {
		int here = q.front().first;
		string str = q.front().second;
		q.pop();

		if (here == b) {
			cout << str << endl;
			break;
		}

		int next = (here * 2) % 10000;
		str.push_back('D');
		if (!visited[next]) {
			q.emplace(next, str);
			visited[next] = true;
		}
		str.pop_back();

		next = here - 1;
		if (next == -1)
			next = 9999;
		str.push_back('S');
		if (!visited[next]) {
			q.emplace(next, str);
			visited[next] = true;
		}
		str.pop_back();

		next = (here * 10) % 10000 + (here * 10) / 10000;
		str.push_back('L');
		if (!visited[next]) {
			q.emplace(next, str);
			visited[next] = true;
		}
		str.pop_back();

		next = (here / 10) + (here % 10) * 1000;
		str.push_back('R');
		if (!visited[next]) {
			q.emplace(next, str);
			visited[next] = true;
		}
		str.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(visited, 0, sizeof(visited));
		cin >> a >> b;
		bfs();
	}
	

	return 0;
}
