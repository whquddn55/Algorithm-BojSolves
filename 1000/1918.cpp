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

string s;
stack<char> st;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
	cin >> s;
	for (char c : s) {
		if (isalpha(c))
			cout << c;
		else {
			switch(c) {
				case '(':
					st.push(c);
					break;
				case ')':
					while(st.top() != '(') {
						cout << st.top();
						st.pop();
					}
					st.pop();
					break;
				case '+':
				case '-':
					while(st.size() && st.top() != '(') {
						cout << st.top();
						st.pop();
					}
					st.push(c);
					break;
				case '*':
				case '/':
					while(st.size() && (st.top() == '*' || st.top() == '/')){
						cout << st.top();
						st.pop();
					}
					st.push(c);
					break;
			}
		}
	}
	while(st.size()) {
		cout << st.top();
		st.pop();
	}
	
    return 0;
}