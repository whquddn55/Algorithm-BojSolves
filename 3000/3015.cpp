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

#define MAX_N 1000005
#define MOD 1000000007

int n;
int arr[MAX_N];


int main() {
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    stack<pii> st;
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        while (st.size() && st.top().first < arr[i]) {
            result += st.top().second;
            st.pop();
        }
        if (st.size() && st.top().first == arr[i]) {
            result += (st.top().second);
            if (st.size() > 1)
                ++result;
            ++st.top().second;
        }
        else {
            result += (!st.empty());
            st.push(pii(arr[i], 1));
        }
    }
    cout << result << endl;

    return 0;
}