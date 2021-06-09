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

ll n;
deque<int> arr;

ll get(int num) {
    ll ret = 0;
    for (int i = 0; i < arr.size(); ++i) {
        ll value = 0;
        if (arr[i] < num) {
            for (int j = 0; j < i; ++j) {
                value *= 10;
                value += arr[j];
            }
            int temp = arr.size() - i - 1;
            while(temp--) 
                value *= 10;
            
            ret += value;
        }
        else if (arr[i] == num) {
            for (int j = 0; j < arr.size(); ++j) {
                if (i == j)
                    continue;
                value *= 10;
                value += arr[j];
            }
            ret += value + 1;
        }
        else {
            for (int j = 0; j < i; ++j) {
                value *= 10;
                value += arr[j];
            }
            value += 1;
            int temp = arr.size() - i - 1;
            while(temp--) 
                value *= 10;
            
            ret += value;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    while(n) {
        arr.push_front(n % 10);
        n /= 10;
    }
    ll offset = 0;
    for (int i = 0; i < arr.size(); ++i) 
        offset = offset * 10 + 1;
    cout << get(0) - offset  << ' ';
    

    for (int i = 1; i < 10; ++i) 
        cout << get(i) << ' ';
    
    
    return 0;
}