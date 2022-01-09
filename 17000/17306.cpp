#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 250005
#define MOD 1'000'000'007

int n;

struct Trie {
    Trie* children[2] = {nullptr, nullptr};
    bool isEnd = false;

    void insert(ll v, int depth) {
        if (depth == -1) {
            isEnd = true;
            return;
        }
        bool flag = v & (1LL << depth);
        if (children[flag] == nullptr)
            children[flag] = new Trie();
        children[flag]->insert(v, depth - 1);
    }
};

Trie* root = new Trie();

int getAns(Trie* const here, bool parentFlag) {
    bool flag = parentFlag | here->isEnd;
    if (here->children[0] != nullptr && here->children[1] != nullptr)
        flag = true;
    
    int res = flag;
    if (here->children[0]) {
        res += getAns(here->children[0], flag);
    }
    if (here->children[1]) {
        res += getAns(here->children[1], flag);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >>n;
    for(int i = 0; i < n; ++i){
        ll v;
        cin >> v;
        int lz = __builtin_clzll(v);
        root->insert(v, 63 - lz);
    }
    
    cout << getAns(root, false) << endl;

    return 0;
}
