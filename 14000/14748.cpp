#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100000

int w;
string arr;

ll lCnt, sCnt, bCnt;
ll wf, wb, v;

ll ans;
bool valid = true;

stack<char> st;

int status;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> w;
	string t;
	while (cin >> t)
		arr.append(t);

	status = 0;
	for (auto e : arr) {
		if (e == 'L')
			lCnt++;
		else if (e == 'S') 
			sCnt++;
		else if (e == 'B') 
			bCnt++;
		else if (e != ',' && e != '(' && e != ')' && e != '[' && e != ']') // 2, 4 조건 걸러냄
			valid = false;

		switch (status) {
		case 0: {
			if (e == 'S')
				status = 1;
			else if (e == 'B' || e == 'L')
				status = 2;
			else
				valid = false;
			break;
		}
		case 1: {
			if (e == ',')
				status = 0;
			else if (e == ')' || e == ']')
				status = 1;
			else
				valid = false;
			break;
		}
		case 2: {
			if (e == '(' || e == '[')
				status = 0;
			else
				valid = false;
			break;
		}
		}

		if (e == '(' || e == '[')
			st.push(e);
		else if (e == ')') {
			if (st.empty() || st.top() != '(')
				valid = false;
			else
				st.pop();
		}
		else if (e == ']') {
			if (st.empty() || st.top() != '[')
				valid = false;
			else
				st.pop();
		}
	}
	if (status != 1 || !st.empty())
		valid = false;

	wf = sCnt + lCnt * 2 + bCnt * 3 - 1;
	wb = lCnt;
	v = sCnt + lCnt * 2 + bCnt * 2;

	ans = wf + wb * w - v + 2;

	cout << (valid ? ans : -1) << endl;

	return 0;
}