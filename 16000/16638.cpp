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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 500005
#define MOD 1000003

int n;
vector<int> arr;
int br[20][2];

int ans = INT_MIN;
void pick(int here) {
	if (here == arr.size() - 1) {
		
		int sum = 0;
		vector<int> temp;
		stack<int> st;
		for (int i = 0; i < arr.size(); ++i) {
			if (arr[i] < 10) {
				for (int c = 0; c < br[i][0]; ++c)
					st.push('(');
				temp.push_back(arr[i]);
				for (int c = 0; c < br[i][1]; ++c) {
					while(st.size() && st.top() != '(') {
						temp.push_back(st.top());
						st.pop();
					}
					st.pop();
				}
				
			}
			else {
				if (arr[i] != '*') {
					while(st.size() && st.top() != '(') {
						temp.push_back(st.top());
						st.pop();
					}
				} else {
					while(st.size() && st.top() == '*') {
						temp.push_back(st.top());
						st.pop();
					}
				}
				st.push(arr[i]);
			}
		}
		while(st.size()) {
			temp.push_back(st.top());
			st.pop();
		}

		for (char e : temp) {
			if (e < 10)
				st.push(e);
			else {
				int res;
				switch(e) {
					case '+': {
						res = st.top();
						st.pop();
						res += st.top();
						st.pop();
						break;
					}
					case '-': {
						res = st.top();
						st.pop();
						res = st.top() - res;
						st.pop();
						break;
					}
					case '*': {
						res = st.top();
						st.pop();
						res *= st.top();
						st.pop();
						break;
					}
				}
				st.push(res);
			}
		}
		
		ans = max(ans, st.top());
		return;
	}
	pick(here + 2);

	br[here][0]++;
	br[here + 2][1]++;
	if (here + 4 >= arr.size())
		pick(here + 2);
	else
		pick(here + 4);
	br[here][0]--;
	br[here + 2][1]--;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	while(n--) {
		char c;
		cin >> c;
		if (isdigit(c))
			c -= '0';
		arr.push_back(c);
	}

	pick(0);
	cout << ans << endl;
	
	return 0;
}
