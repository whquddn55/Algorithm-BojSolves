#include <bits/stdc++.h>
#include <unordered_map>
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

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100001

int n, k, q;
int arr[MAX_N];
unordered_map<int, int> m;
int prv[MAX_N];

void bfs() {
	for (int i = 1; i <= n; i++) 
		prv[i] = i;

	queue<int> q;
	q.emplace(1);
	prv[1] = 0;

	while (!q.empty()) {
		int hereidx = q.front();
		q.pop();

		int here = arr[hereidx]; 
		int checker = 1;
		for (int i = 0; i < k; i++) {
			if (i)
				checker <<= 1;
			if (m.find(here ^ checker) == m.end())
				continue;
			int nextidx = m[here ^ checker];
			if (prv[nextidx] != nextidx)
				continue;

			q.emplace(nextidx);
			prv[nextidx] = hereidx;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		int num = 0;
		for (auto e : str) 
			num = (num << 1) | (e == '1');
		m[num] = i;
		arr[i] = num;
	}
	
	bfs();

	cin >> q;
	while (q--) {
		int to;
		cin >> to;

		stack<int> st;
		while (to != prv[to]) {
			st.push(to);
			to = prv[to];
		}
		if (to != 0)
			cout << -1 << endl;
		else {
			while (st.size()) {
				cout << st.top() << ' ';
				st.pop();
			}
			cout << endl;
		}
	}

	return 0;
}
