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

#define MAX_N 3005

int n;
pair<pii, pii> arr[MAX_N];
int result[MAX_N];

int ccw(pii& a, pii& b, pii& c) {
    int value = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    if (value < 0)
        return -1;
    else if (value > 0)
        return 1;
    else
        return 0;
}

int parent[MAX_N];
int level[MAX_N];
int find(int u) {
    if (parent[u] == u)
        return u;
    
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;
    
    if (level[u] > level[v])
        swap(u, v);
    if (level[u] == level[v])
        ++level[v];

    parent[u] = v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            if (find(i) == find(j))
                continue;

            int result1 = ccw(arr[i].first, arr[i].second, arr[j].first) * ccw(arr[i].first, arr[i].second, arr[j].second);
            int result2 = ccw(arr[j].first, arr[j].second, arr[i].first) * ccw(arr[j].first, arr[j].second, arr[i].second);

            if (result1 <= 0 && result2 <= 0) {
                if ((result1 == 0 && result2 == 0)) {
                    if ((arr[i].second.first - arr[i].first.first) * (arr[j].second.second - arr[j].first.second) == (arr[i].second.second - arr[i].first.second) * (arr[j].second.first - arr[j].first.first)) {
                        if ((((arr[i].first.first <= arr[j].second.first && arr[j].second.first <= arr[i].second.first) || (arr[i].first.first <= arr[j].first.first && arr[j].first.first <= arr[i].second.first) || (arr[i].second.first <= arr[j].second.first && arr[j].second.first <= arr[i].first.first) || (arr[i].second.first <= arr[j].first.first && arr[j].first.first <= arr[i].first.first)) && 
                            ((arr[i].first.second <= arr[j].second.second && arr[j].second.second <= arr[i].second.second) || (arr[i].first.second <= arr[j].first.second && arr[j].first.second <= arr[i].second.second) || (arr[i].second.second <= arr[j].second.second && arr[j].second.second <= arr[i].first.second) || (arr[i].second.second <= arr[j].first.second && arr[j].first.second <= arr[i].first.second))) ||
                            (((arr[j].first.first <= arr[i].second.first && arr[i].second.first <= arr[j].second.first) || (arr[j].first.first <= arr[i].first.first && arr[i].first.first <= arr[j].second.first) || (arr[j].second.first <= arr[i].second.first && arr[i].second.first <= arr[j].first.first) || (arr[j].second.first <= arr[i].first.first && arr[i].first.first <= arr[j].first.first)) && 
                            ((arr[j].first.second <= arr[i].second.second && arr[i].second.second <= arr[j].second.second) || (arr[j].first.second <= arr[i].first.second && arr[i].first.second <= arr[j].second.second) || (arr[j].second.second <= arr[i].second.second && arr[i].second.second <= arr[j].first.second) || (arr[j].second.second <= arr[i].first.second && arr[i].first.second <= arr[j].first.second))) ) {
                                merge(i, j);
                            }
                    }
                    else
                        merge(i, j);
                }
                else
                    merge(i, j);
            }
        }

    for (int i = 0; i < n; ++i)
        ++result[find(i)];
    
    int cnt = 0;
    int maxValue = 0;
    for (int i = 0; i < n; ++i)
        if (result[i]) {
            ++cnt;
            maxValue = max(maxValue, result[i]);
        }
    cout << cnt << endl << maxValue << endl;

	return 0;
}
