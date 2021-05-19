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
pii tree[4 * MAX_N];
vector<pii> q1;
vector<pair<pii, pii>> q2;

pii init(int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (nodeLeft == nodeRight)
        return tree[nodeIndex] = {arr[nodeLeft], 0};
    int mid = (nodeLeft + nodeRight) / 2;
    pii leftValue = init(nodeLeft, mid, nodeIndex * 2);
    pii rightValue = init(mid + 1, nodeRight, nodeIndex * 2 + 1);
    pii maxValue = {0, 0};
    int arr[4] = {leftValue.first, leftValue.second, rightValue.first, rightValue.second};
    for (int i = 0; i < 4; ++i) {
        if (maxValue.first <= arr[i]) {
            maxValue.second = maxValue.first;
            maxValue.first = arr[i];
        }
        else if (maxValue.second < arr[i]) {
            maxValue.second = arr[i];
        }
    }
    return tree[nodeIndex] = maxValue;
}

pii update(int index, int value, int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (index < nodeLeft || nodeRight < index)
        return tree[nodeIndex];
    if (nodeLeft == nodeRight) 
        return tree[nodeIndex] = {value, 0};
    
    int mid = (nodeLeft + nodeRight) / 2;
    pii leftValue = update(index, value, nodeLeft, mid, nodeIndex * 2);
    pii rightValue = update(index, value, mid + 1, nodeRight, nodeIndex * 2 + 1);
    pii maxValue = {0, 0};
    int arr[4] = {leftValue.first, leftValue.second, rightValue.first, rightValue.second};
    for (int i = 0; i < 4; ++i) {
        if (maxValue.first <= arr[i]) {
            maxValue.second = maxValue.first;
            maxValue.first = arr[i];
        }
        else if (maxValue.second < arr[i]) {
            maxValue.second = arr[i];
        }
    }
    return tree[nodeIndex] = maxValue;
}

pii query(int l, int r, int nodeLeft = 0, int nodeRight = n - 1, int nodeIndex = 1) {
    if (r < nodeLeft || nodeRight < l)
        return {0, 0};
    if (l <= nodeLeft && nodeRight <= r)
        return tree[nodeIndex];

    int mid = (nodeLeft + nodeRight) / 2;
    pii leftValue = query(l, r, nodeLeft, mid, nodeIndex * 2);
    pii rightValue = query(l, r, mid + 1, nodeRight, nodeIndex * 2 + 1);
    pii maxValue = {0, 0};
    int arr[4] = {leftValue.first, leftValue.second, rightValue.first, rightValue.second};
    for (int i = 0; i < 4; ++i) {
        if (maxValue.first <= arr[i]) {
            maxValue.second = maxValue.first;
            maxValue.first = arr[i];
        }
        else if (maxValue.second < arr[i]) {
            maxValue.second = arr[i];
        }
    }
    return maxValue;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    init();
    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) 
            update(b - 1, c);
        else {
            pii result = query(b - 1, c - 1);
            cout << result.first + result.second  << endl;
        }
    }


	return 0;
}
