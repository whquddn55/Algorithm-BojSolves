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
#define MAX_N 100005

int n;
int arr[MAX_N];
int tree[4 * MAX_N];

int init(int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (nodeLeft == nodeRight)
        return tree[nodeIndex] = nodeLeft;
    int mid = (nodeLeft + nodeRight) / 2;
    int leftIndex = init(nodeLeft, mid, nodeIndex * 2);
    int rightIndex = init(mid + 1, nodeRight, nodeIndex * 2 + 1);
    return tree[nodeIndex] = (arr[leftIndex] <= arr[rightIndex]) ? leftIndex : rightIndex;
}

int update(int index, int value, int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (index < nodeLeft || nodeRight < index)
        return tree[nodeIndex];
    if (nodeLeft == nodeRight) {
        arr[index] = value;
        return tree[nodeIndex] = index;
    }
    
    int mid = (nodeLeft + nodeRight) / 2;
    int leftIndex = update(index, value, nodeLeft, mid, nodeIndex * 2);
    int rightIndex = update(index, value, mid + 1, nodeRight, nodeIndex * 2 + 1);
    return tree[nodeIndex] = (arr[leftIndex] <= arr[rightIndex]) ? leftIndex : rightIndex;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    init();
    int q;
    cin >> q;
    while(q--) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(b - 1, c);
        }
        else
            cout << tree[1] + 1 << endl;
    }

	return 0;
}
