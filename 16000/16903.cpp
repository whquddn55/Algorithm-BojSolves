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
#define MAX_N 105
#define MOD 1000000007

struct Trie {
	int cnt;
	Trie* nxt[2];

	Trie()
		:cnt(0) {
			memset(nxt, NULL, sizeof(nxt));
		}

	~Trie() {
		for (int i = 0; i < 2; ++i)
			if (nxt[i])
				delete nxt[i];
	}

	void insert(int value, int remain) {
		if (remain == 0) {
			++cnt;
			return;
		}
		bool bit = value & (1 << 31);
		if (nxt[bit] == NULL)
			nxt[bit] = new Trie();
		nxt[bit]->insert(value << 1, remain - 1);
	}
	
	bool remove(int value, int remain) {
		if (remain == 0){
			--cnt;
			return cnt;
		}
		bool bit = value & (1 << 31);
		bool res = nxt[bit]->remove(value << 1, remain - 1);
		if (res == false) {
			delete nxt[bit];
			nxt[bit] = NULL;
		}
		if (nxt[0] == nxt[1])
			return false;
		return true;
	}

	int find(int value, int remain){
		if (remain == 0) 
			return 0;
		bool bit = value & (1 << 31);
		if (nxt[bit]) {
			return nxt[bit]->find(value << 1, remain - 1) | (bit << (remain - 1));
		}
		else if (nxt[!bit]){
			return nxt[!bit]->find(value << 1, remain - 1) | (!bit << (remain - 1));
		}
		else
			return -1;
	}

	bool find2(int value, int remain) {
		if (remain == 0) 
			return true;
		bool bit = value & (1 << 31);
		if (nxt[bit])
			return nxt[bit]->find2(value << 1, remain - 1);
		return false;
	}
};

int m;
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> m;
	Trie* root = new Trie();
	root->insert(0, 32);
	while(m--) {
		int c, v;
		cin >> c >> v;
		if (c == 1) 
			root->insert(v, 32);
		else if (c == 2)
			root->remove(v, 32);
		else {
			int ret = root->find(~v, 32);
			assert(ret >= 0);
			cout << (v ^ ret) << endl;
		}
	}
	
	
	return 0;
}
