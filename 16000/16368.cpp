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
#define MAX_N 2005
#define MOD 1000000

int m, n, w, h;
int arr[MAX_N];
priority_queue<pii> pq;
queue<pii> working;
queue<pii> resting;
vector<int> ans[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
	cin >> m >> n >> w >> h;
	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		arr[i] /= w;
		pq.emplace(arr[i], i);
	}

	bool feasible = true;
	for (int i = 1; i <= n; ++i)  {
		int need;
		cin >> need;

		while(working.size() && working.front().first == i) {
			resting.emplace(i + h, working.front().second);
			working.pop();
		}
		need -= working.size();

		while(resting.size() && resting.front().first == i) {
			if (arr[resting.front().second])
				pq.emplace(arr[resting.front().second], resting.front().second);
			resting.pop();
		}

		if (pq.size() < need) {
			feasible = false;
			break;
		}

		while(need--) {
			arr[pq.top().second]--;
			working.emplace(i + w, pq.top().second);
			ans[pq.top().second].push_back(i);
			pq.pop();
		}
	}

	if (feasible) {
		cout << 1 << endl;
		for(int i = 0; i < m; ++i,cout<<endl)
			for (auto e : ans[i])
				cout << e << ' ';
	} else {
		cout << -1 << endl;
	}

	
	
	return 0;
}