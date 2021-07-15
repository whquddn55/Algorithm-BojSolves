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
#define MAX_N 100005
#define MOD 1000000007

string n;
int k;

queue<string> q;
vector<string> arr;
set<string> inQ;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> k;

	q.emplace(n);
	inQ.insert(n);

	for (int i = 0; i < k; ++i) {
		int qsize = q.size();
		inQ.clear();
		while(qsize--) {
			string here = q.front();
			q.pop();

			for (int j = 0; j < here.size(); ++j)
				for (int k = j + 1; k < here.size(); ++k) {
                    if (j == 0 && here[k] == '0')
                        continue;
                    swap(here[j], here[k]);
                    if (inQ.find(here) == inQ.end()) {
                        q.emplace(here);
                        inQ.insert(here);
                    }
                    swap(here[j], here[k]);
				}
		}
	}

	if (q.size() == 0)
		cout << -1 << endl;
	else {
		while(q.size()) {
			arr.emplace_back(q.front());
			q.pop();
		}
		sort(arr.begin(), arr.end());
		cout << arr.back() << endl;
	}
	

	return 0;
}
