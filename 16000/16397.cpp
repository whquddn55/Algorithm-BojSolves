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

#define MAX_N 100000

int n, t, g;

queue<pii> q;
bool visited[MAX_N];

int bfs() {

    q.emplace(n, 0);
    visited[n] = true;

    while(q.size()) {
        int here = q.front().first;
        int hereCost = q.front().second;
        q.pop();


        if (hereCost > t) 
            return -1;

        if (here == g) 
            return hereCost;

        if (here + 1 < 100000 && !visited[here + 1]) {
            q.emplace(here + 1, hereCost + 1);
            visited[here + 1] = true;
        }

        int next = here * 2;
        for (int i = 1; i < 100000; i *= 10)
            if (next / i < 10) {
                next -= i;
                break;
            };

        if (here != 0 && here * 2 < 100000 && !visited[next]) {
            q.emplace(next, hereCost + 1);
            visited[next] = true;
        }
    }

    return -1;
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin >> n >> t >> g;

    int result = bfs();

    if (result == -1)
        cout << "ANG" << endl;
    else
        cout << result << endl;

	return 0;
}