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
#define MAX_N 105

int n;
string arr[MAX_N];
bool adj[300][300];
int ind[300];

void makeEdge(int f, int t, int index) {
	if (t - f == 1 || index == 10)
		return;
	char prv = 0;
	int prvIndex = -1;
	for (int i = f; i < t; ++i) {
		if (arr[i].size() <= index) 
			continue;
		if (prvIndex == -1){
			prvIndex = i;
			prv = arr[i][index];
		}
		else {
			if (prv != arr[i][index]) {
				if (!adj[prv][arr[i][index]]){
					adj[prv][arr[i][index]] = true;
					ind[arr[i][index]]++;
				}
				makeEdge(prvIndex, i, index + 1);
				prv = arr[i][index];
				prvIndex = i;
			}
		}
	}
	if (prvIndex != -1)
		makeEdge(prvIndex, t, index + 1);
}

void tpsort() {
	string ans;
	queue<char> q;
	for (char i = 'a'; i <= 'z'; ++i) 
		if (ind[i] == 0)
			q.emplace(i);

	int status = 0; // 1 : 많음, 2 : 불가능
	while(q.size()) {
		char here = q.front();
		q.pop();

		if (q.size())
			status |= 1;

		ans.push_back(here);
		
		for (char i = 'a'; i <= 'z'; ++i) {
			if (adj[here][i]) {
				ind[i]--;
				if (ind[i] == 0) {
					q.emplace(i);
				}
			}
		}
	}
	for (char i = 'a'; i <= 'z'; ++i)
		if (ind[i]>0) 
			status |= 2;
		
	if (status & 2)
		cout << '!' << endl;
	else if (status & 1)
		cout << '?' << endl;
	else 
		cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> n;
	fill(ind, ind + 300, -1);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		for (char c : arr[i])
			ind[c] = 0;

		for (int j = 0; j < i; ++j) {
			if ((arr[j].size() > arr[i].size()) && (arr[j].substr(0, arr[i].size()) == arr[i])) {
				cout << '!' << endl;
				return 0;
			}
		}
	}

	makeEdge(0, n, 0);
	tpsort();
	
	return 0;
}