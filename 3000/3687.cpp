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
#define MAX_N 105
#define MOD 1'000'000'007

int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

/*
    2 : 1
    3 : 7
    4 : 4
    5 : 2, 3, 5
    6 : 0, 6, 9
    7 : 8

    홀수 : 5(3)
    짝수 : 2(1)
*/

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;

        if (n == 2) 
            cout << pii(1, 1) << endl;
        else if (n == 3)
            cout << pii(7, 7) << endl;
        else if (n == 4) 
            cout << pii(4, 11) << endl;
        else if (n == 5)
            cout << pii(2, 71) << endl;
        else if (n == 6)
            cout << pii(6, 111) << endl;
        else if (n == 10)
            cout << pii(22, 11111) << endl;
        else {
            string a;
            int t = n / 2 - 1;
            a.push_back(n % 2 == 0 ? '1' : '7');
            while (t--) {
                a.push_back('1');
            }

            string b = "";
            if (n % 7 == 0) b = "8";
            else if (n % 7 == 1) b = "10";
            else if (n % 7 == 2) b = "18";
            else if (n % 7 == 3){ b = "200"; n -= 7;}
            else if (n % 7 == 4) b = "20";
            else if (n % 7 == 5) b = "28";
            else if (n % 7 == 6) b = "68";
            while(n >= 14) {
                b.push_back('8');
                n -= 7;
            }
            cout << b << ' ' << a << endl;
        }
    }

    return 0;
}
