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

#define all(x) (x).begin(), (x).end()
#define INF (INT_MAX / 2)
#define MAX_N 1005
#define MOD 1000000

int tc;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;
        switch(s.back()) {
            case 'a':
                s.push_back('s');
            break;
            case 'i':
            case 'y':
                s.pop_back();
                s.append("ios");
            break;
            case 'l':
                s.append("es");
            break;
            case 'n':
                s.pop_back();
                s.append("anes");
            break;
            case 'e':
                if (*(++s.rbegin()) == 'n') {
                    s.pop_back();
                    s.pop_back();
                    s.append("anes");
                }
                else {
                    s.append("us");
                }
            break;
            case 'o':
                s.push_back('s');
            break;
            case 'r':
                s.push_back('e');
                s.push_back('s');
            break;
            case 't':
                s.push_back('a');
                s.push_back('s');
            break;
            case 'u':
                s.push_back('s');
            break;
            case 'v':
                s.push_back('e');
                s.push_back('s');
            break;
            case 'w':
                s.push_back('a');
                s.push_back('s');
            break;
            default:
                s.append("us");
            break;
        }

        cout << s << endl;
    }
    
    return 0;
}
