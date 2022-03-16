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
#define MAX_N 1000005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

int n;
string s;
vector<int> arr;
bool found = false;

void get(int checkIndex) {
    if (arr.size() == n) {
        found = true;
        return;
    }
    int from, to;
    if (s[checkIndex] == '-') {
        from = -10; to = -1;
    } else if (s[checkIndex] == '0') {
        from = 0; to = 0;
    } else {
        from = 1; to = 10;
    }

    for (int num = from; num <= to; ++num) {
        arr.push_back(num);

        int sum = 0;
        bool possible = true;
        for (int i = arr.size() - 1; i >= 0; --i) {
            sum += arr[i];

            if (s[checkIndex - (arr.size() - 1) + i] == '-') possible &= sum < 0;
            else if (s[checkIndex - (arr.size() - 1) + i] == '0') possible &= sum == 0;
            else possible &= sum > 0;
        }
        if (!possible) {
            arr.pop_back();
            continue;
        }

        get(checkIndex + arr.size() + 1);
        if (found == true) break;
        arr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> s;
    reverse(all(s));
    get(0);
    reverse(all(arr));
    for (auto e : arr)
        cout << e << ' ';
    cout << endl;
    
    return 0;
}
