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
#define MAX_N 100005
#define MOD 1000003

struct Trie {
	bool isEnd;
	map<int, Trie*> nxt;

	Trie()
		:isEnd(false) {
			nxt.clear();
		}
	~Trie() {
		for (auto e : nxt) 
			delete e.second;
	}
	
	void insert(string& s, int iter = 0) {
		if (iter == s.size()) {
			isEnd = true;
			return;
		}
		int idx = s[iter] - 'a';
		if (nxt.find(idx) == nxt.end())
			nxt[idx] = new Trie();
		nxt[idx]->insert(s, iter + 1);
	}

	int cnt(int pushed) {
		int nxtCnt = isEnd;
		for (int i = 0; i < 26; ++i)
			if (nxt.find(i) != nxt.end())
				++nxtCnt;


		if (nxtCnt == 1) {
			for (int i = 0; i < 26; ++i)
				if (nxt.find(i) != nxt.end())
					return nxt[i]->cnt(pushed) + (isEnd ? pushed : 0);
			return pushed;
		}
		int sum = (isEnd ? pushed : 0);
		for (int i = 0; i < 26; ++i)
			if (nxt.find(i) != nxt.end())
				sum += nxt[i]->cnt(pushed + 1);
		return sum;
	}
};

int n;
string arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	while(cin >> n) {
		Trie root;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			root.insert(arr[i]);
		}
		int sum = 0;
		for (int i = 0; i < 26; ++i) {
			if (root.nxt[i])
				sum += root.nxt[i]->cnt(1);
		}

		cout.precision(2);
		cout << fixed;

		cout << (double)sum / n  << endl;
	}
	
	return 0;
}
