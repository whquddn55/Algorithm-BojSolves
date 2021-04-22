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

int n, k, m;
vector<int> tube[MAX_N];
vector<int> isIn[MAX_N * 100];

queue<pii> q;
bool visited[MAX_N * 100];
bool visitedTube[MAX_N];
int bfs() {
    q.emplace(0, 1);
    visited[0] = true;

    while(q.size()) {
        int here = q.front().first;
        int hereCost = q.front().second;
        q.pop();

        if (here == n - 1)
            return hereCost;

        for(auto tubeIndex : isIn[here]) {
            if (visitedTube[tubeIndex])
                continue;
            visitedTube[tubeIndex] = true;
            for (auto next : tube[tubeIndex]) {
                if (next == here || visited[next])
                    continue;
                
                visited[next] = true;
                q.emplace(next, hereCost + 1);
            }
        }
    }
    return -1;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin >> n >> k >> m;
    for (int i = 0; i < m; ++i) {
        tube[i].reserve(k);
        for (int j = 0; j < k; ++j) {
            int t;
            cin >> t;
            --t;
            tube[i].emplace_back(t);
            isIn[t].emplace_back(i);
        }
    }

    cout << bfs() << endl;
   
	return 0;
}