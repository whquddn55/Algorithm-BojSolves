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
#define MOD 1000000007

int n;
int arr[MAX_N];
int lis[MAX_N];
int dis[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    for (int i = n - 1; i >= 0; --i) {
        lis[i] = 1;
        for (int j = n - 1; j > i; --j)
            if (arr[i] < arr[j])
                lis[i] = max(lis[i], lis[j] + 1);
    }
    for (int i = 0; i < n; ++i) {
        dis[i] = 1;
        for (int j = 0; j < i; ++j)
            if (arr[i] < arr[j])
                dis[i] = max(dis[i], dis[j] + 1);
    }
    int result = 0;
    for (int i = 0; i < n; ++i) 
        result = max(result, lis[i] + dis[i] - 1);
    
    cout << result << endl;
    
    
    return 0;
}