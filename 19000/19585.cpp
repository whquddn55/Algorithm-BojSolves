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
#define MAX_N 2005
#define MOD 1000000007

int cnt[MAX_N];

struct Trie {
	bool isEnd;
	map<char, Trie*> nxt;

	Trie() 
		: isEnd(0) {
			nxt.clear();
		}

	void insert(string& s, int iter = 0) {
		if (s.size() == iter) {
			isEnd = true;
			return;
		}
		int id = s[iter] - 'a';
		if (nxt.find(id) == nxt.end()) 
			nxt[id] = new Trie();
		nxt[id]->insert(s, iter + 1);
	}

	void find(string& s, bool back, int iter = 0) {
		if (s.size() == iter) 
			return;
		if (isEnd) 
			cnt[back ? s.size() - iter : iter]++;
		int id = s[iter] - 'a';
		if (nxt.find(id) == nxt.end())
			return;
		return nxt[id]->find(s, back, iter + 1);
	}
};

int c, n, q;
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	Trie* color = new Trie();
	Trie* nick = new Trie();

	cin >> c >> n;
	while(c--) {
		string s;
		cin >> s;
		color->insert(s);
	}
	while(n--) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		nick->insert(s);
	}

	cin >> q;
	while(q--) {
		memset(cnt, 0, sizeof(cnt));

		string s;
		cin >> s;
		color->find(s, false);
		reverse(s.begin(),s.end());
		nick->find(s, true);

		bool res = false;
		for (int i = 0; i < s.size(); ++i) 
			if (cnt[i] == 2)
				res = true;
		
		cout << (res ? "Yes" : "No") << endl;
	}
	
	return 0;
}
