#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 303030;
int n;
ll sx[101010], sy[101010], ex[101010], ey[101010];
ll tree[MAX_N * 4];
ll lazy[MAX_N * 4];
vector<ll> cor;
void updateLazy(int nodeLeft, int nodeRight, int id) {
    if (lazy[id]) {
        tree[id] += lazy[id];
        if (nodeLeft != nodeRight) {
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void update(int left, int right, ll val, int nodeLeft, int nodeRight, int id = 1) {
    int mid = (nodeLeft + nodeRight) / 2;
    updateLazy(nodeLeft, nodeRight, id);
    if (right < nodeLeft || nodeRight < left)       
        return;
    if (left <= nodeLeft && nodeRight <= right) {
        tree[id] +=  val;
        if (nodeLeft != nodeRight) {
            lazy[id * 2] += val;
            lazy[id * 2 + 1] += val;
        }
        return;
    }
    update(left, right, val, nodeLeft, mid, id * 2);
    update(left, right, val, mid + 1, nodeRight, id * 2 + 1);
    tree[id] = max(tree[id * 2],tree[id * 2 + 1]);
}

ll query(int left, int right, int nodeLeft, int nodeRight, int id = 1) {
    int mid = (nodeLeft + nodeRight) / 2;
    updateLazy(nodeLeft, nodeRight, id);
    if (right < nodeLeft || nodeRight < left)
        return 0;
    if (left <= nodeLeft && nodeRight <= right)
        return tree[id];

    return max(query(left, right, nodeLeft, mid, id * 2),query(left, right, mid + 1, nodeRight, id * 2 + 1));
}
int main() 
{

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cin >> sx[i] >> ey[i] >> ex[i] >> sy[i];
        cor.push_back(sy[i]);
        cor.push_back(ey[i]);
    }

    sort(cor.begin(), cor.end());

    cor.erase(unique(cor.begin(), cor.end()), cor.end());

    
    for (int i = 0; i < n; i++)
    {
        sy[i] = lower_bound(cor.begin(), cor.end(), sy[i]) - cor.begin();
        ey[i] = lower_bound(cor.begin(), cor.end(), ey[i]) - cor.begin();
        update(sy[i], ey[i], 1, 0, cor.size() - 1, 1);
    }
    
    ll ans = query(0, cor.size() - 1, 0, cor.size() - 1, 1);
    ll cnt = 0;
    vector<pair<ll,ll> > v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({ sy[i],ey[i] });
    }
    sort(v.begin(), v.end());
    ll s = v[0].first;
    ll e = v[0].second;
    update(s, e, -1, 0, cor.size(), 1);
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    pq.push(e);
    cnt = 1;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, query(0, cor.size() - 1, 0, cor.size() - 1, 1) + cnt);
        
        while (!pq.empty() && pq.top() < v[i].first) {
            cnt--;
            pq.pop();
        }
        pq.push(v[i].second);
        cnt++;
        update(v[i].first, v[i].second, -1, 0, cor.size() - 1, 1);
    }
    ans = max(ans, query(0, cor.size() - 1, 0, cor.size() - 1, 1) + cnt);
    cout << ans;
}
