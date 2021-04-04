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

#define MAX_N 20

string str;
stack<char> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> str;
    reverse(str.begin(), str.end());
    
    bool result = true;
    int i = 0;
    for (char c : str) {
        if (c == 'P') {
            if (st.empty())
                st.push('P');
            else {
                if (st.top() == 'P') {
                    if (st.size() < 3)
                        result = false;
                    else  {
                        st.pop();
                        st.pop();
                    }
                }
                else
                    st.push('P');
            }
        }
        else {
            if (st.empty() || st.top() == 'A')
                result = false;
            else {
                st.push('A');
            }
        }


        if (!result)
            break;
    }
    if (st.empty() || st.size() >= 2 || st.top() == 'A')
        result = false;

    cout << (result ? "PPAP" : "NP") << endl;
    
	return 0;
}
