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
#define MAX_N 300005
#define MOD 9901

int n, c, m;
int arr[MAX_N];

pii q[10005];
int idx[10005];
int cnt[10005];
int maxValue = 0;
int maxIndex = 0;

void query(pii prv, pii now) {
    for (int i = prv.first; i < now.first; ++i)
        cnt[arr[i]]--;
    for (int i = prv.first - 1; i >= now.first; --i) 
        cnt[arr[i]]++;
    for (int i = prv.second + 1; i <= now.second; ++i)
        cnt[arr[i]]++;
    for (int i = prv.second; i > now.second; --i)
        cnt[arr[i]]--;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i]--;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        idx[i] = i;
        cin >> q[i];
        q[i].first--;
        q[i].second--;
    }

    sort(idx, idx + m, [](int a, int b) -> bool {
        return pii(q[a].first / 8000, q[a].second) < pii(q[b].first / 8000, q[b].second);
    });

    int result[10005];
    memset(result, -1, sizeof(result));
    for (int i = 0; i < m; ++i) {
        pii prv;
        pii now = q[idx[i]];
        if (i == 0)
            prv = {0, -1};
        else
            prv = q[idx[i - 1]];

        query(prv, now);
        int maxValue = 0;
        int maxIndex = 0;
        for (int i = 0; i < c; ++i)
            if (maxValue < cnt[i]) {
                maxValue = cnt[i];
                maxIndex = i;
            }
        if (maxValue > (q[idx[i]].second - q[idx[i]].first + 1) / 2)
            result[idx[i]] = maxIndex + 1;
    }
    for (int i = 0; i < m; ++i)
        if (result[i] != -1)
            cout << "yes " << result[i] << endl;
        else
            cout << "no" << endl;

    return 0;
}