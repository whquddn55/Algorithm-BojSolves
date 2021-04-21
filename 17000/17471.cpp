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

int n;
int arr[MAX_N];
vector<int> adj[MAX_N];
bool rb[MAX_N];
int result = INF;

bool visited[MAX_N];
int dfs(int here) {
    int result = arr[here];
    visited[here] = true;

    for (auto next : adj[here])
        if (!visited[next] && (rb[next] == rb[here])) 
            result += dfs(next);
    return result;
}

void pick(int toPick) {
    if (toPick == n) {
        memset(visited, 0, sizeof(visited));
        int start1 = -1, start2 = -1;
        for (int i = 0; i < n; ++i) {
            if (rb[i])
                start1 = i;
            else
                start2 = i;
        }
        if (start1 == -1 || start2 == -1) 
            return;
        
        int v1 = dfs(start1);
        int v2 = dfs(start2);

        for (int i = 0; i < n; ++i)
            if (!visited[i])
                return;
            

        result = min(result, abs(v1 - v2));

        return;
    }

    rb[toPick] = true;
    pick(toPick + 1);
    rb[toPick] = false;
    pick(toPick + 1);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        while(m--) {
            int to;
            cin >> to;
            --to;
            adj[i].emplace_back(to);
        }
    }

    pick(0);

    cout << (result == INF ? -1 : result) << endl;
    
	return 0;
}