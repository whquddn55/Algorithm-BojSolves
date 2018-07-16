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

int n;
int r[4];
int f[4];

string arr[5][5] = {
{ "New Customer", "Promising", "About to Sleep", "Lost", "Lost" },
{ "Potential Loyalist", "Potential Loyalist" , "About to Sleep", "Hibernating", "Lost"},
{ "Potential Loyalist", "Potential Loyalist", "Need Attention", "About to Leave", "About to Leave"},
{ "Loyal Customer", "Loyal Customer", "Loyal Customer", "About to Leave", "About to Leave"},
{ "Champion", "Loyal Customer", "Loyal Customer", "About to Leave", "Can't Lose Them"} }; // (r, f)

map<string, pii> m;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	for (int i = 0; i < 4; i++)
		cin >> r[i];
	for (int i = 0; i < 4; i++)
		cin >> f[i];

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		string b;
		cin >> a >> b;
		if (a == 1) {
			m[b].first = i;
			m[b].second++;
		}
		else {
			pii e = m[b];
			if (e.second == 0)
				cout << "None" << endl;
			else {
				int rIdx = lower_bound(r, r + 4, i - m[b].first) - r;
				int fIdx = lower_bound(f, f + 4, m[b].second) - f;
				/*cout << pii(fIdx, rIdx) << endl;*/
				cout << arr[fIdx][rIdx] << endl;
			}
		}
	}

	return 0;
}