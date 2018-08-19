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

#define MAX_N 1000001

int n, m;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		q.emplace(i);

	int cnt = 0;
	cout << "<";
	while (q.size()) {
		cnt++;
		if (cnt == m) {
			cout << q.front() << (q.size() == 1 ? ">" : ", ");
			cnt = 0;
		}
		else
			q.emplace(q.front());
		q.pop();
	}
	
	return 0;
}