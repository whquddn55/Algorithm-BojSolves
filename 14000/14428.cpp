#include <bits/stdc++.h>
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
#define MAX_N 100005

int n, m;
int arr[MAX_N];
pii tree[MAX_N * 4];

pii update(int index, int value, int nodeLeft = 0, int nodeRight = n - 1, int treeIndex = 1) {
    if (index < nodeLeft || nodeRight < index)
        return tree[treeIndex];
    if (nodeLeft == nodeRight) 
        return tree[treeIndex] = {value, index};
    int mid = (nodeLeft + nodeRight) / 2;
    return tree[treeIndex] = min(update(index, value, nodeLeft, mid, treeIndex * 2), update(index, value, mid + 1, nodeRight, treeIndex * 2 + 1));

}

pii query(int left, int right, int nodeLeft = 0, int nodeRight = n - 1, int treeIndex = 1) {
    if (left <= nodeLeft && nodeRight <= right)
        return tree[treeIndex];
    if (nodeRight < left || right < nodeLeft)
        return {INF, INF};
    int mid = (nodeLeft + nodeRight) / 2;
    return min(query(left, right, nodeLeft, mid, treeIndex * 2), query(left, right, mid + 1, nodeRight, treeIndex * 2 + 1));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n ;++i) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    cin >> m;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) 
            update(b - 1, c);
        else 
            cout << query(b - 1, c - 1).second + 1 << endl;
    }
    
	return 0;
}
