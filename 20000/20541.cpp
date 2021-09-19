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
#define MAX_N 400005
#define MOD 1'000'000'007
#define MOD2 1'000'000'009

struct Dir {
	string name;
	Dir* parent = NULL;
	map<string, Dir*> folder;
	set<string> ele;
}* root;

int n;

pii dfs(Dir* here) {
	pii res = {1, here->ele.size()};
	for (auto& p : here->folder) {
		if (p.second != NULL) {
			pii child = dfs(p.second);
			res.first += child.first;
			res.second += child.second;
			delete p.second;
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	root = new Dir();
	Dir* here = root;
	root->parent = root;
	root->name = "album";
	while(n--) {
		string c1, c2;
		cin >> c1 >> c2;
		if (c1 == "mkalb") {
			if (here->folder.count(c2))
				cout << "duplicated album name" << endl;
			else {
				Dir* d = new Dir();
				d->parent = here;
				d->name = c2;
				here->folder.emplace(c2, d);
			}
		} else if (c1 == "rmalb") {
			if (c2 == "-1") {
				if (here->folder.size() == 0){
					cout << pii(0, 0) << endl;
					continue;
				}
				pii res = dfs(here->folder.begin()->second);
				delete here->folder.begin()->second;
				here->folder.erase(here->folder.begin()->first);
				cout << res << endl;
			} else if (c2 == "0") {
				pii res = {0, 0};
				for(auto& p : here->folder) {
					pii temp = dfs(p.second);
					res.first += temp.first;
					res.second += temp.second;
					delete p.second;
				}
				here->folder.clear();
				cout << res << endl;
			} else if (c2 == "1") {
				if (here->folder.size() == 0){
					cout << pii(0, 0) << endl;
					continue;
				}
				pii res = dfs(here->folder.rbegin()->second);
				delete here->folder.rbegin()->second;
				here->folder.erase(here->folder.rbegin()->first);
				cout << res << endl;
			} else {
				auto found = here->folder.find(c2);
				if (found != here->folder.end()) {
					cout << dfs(found->second) << endl;
					delete found->second;
					here->folder.erase(c2);
				}
				else
					cout << pii(0, 0) << endl;
			}
		} else if (c1 == "insert") {
			if (here->ele.count(c2))
				cout << "duplicated photo name" << endl;
			else 
				here->ele.insert(c2);
		} else if (c1 == "delete") {
			if (c2 == "-1") {
				if (here->ele.size() == 0){
					cout << 0 << endl;
					continue;
				}
				cout << here->ele.erase(*here->ele.begin()) << endl;
			} else if (c2 == "0") {
				cout << here->ele.size() << endl;
				here->ele.clear();
			} else if (c2 == "1") {
				if (here->ele.size() == 0){
					cout << 0 << endl;
					continue;
				}
				cout << here->ele.erase(*here->ele.rbegin()) << endl;
			} else {
				cout << here->ele.erase(c2) << endl;
			}
		} else if (c1 == "ca") {
			if (c2 == "..") {
				here = here->parent;
				cout << here->name << endl;
			} else if (c2 == "/") {
				here = root;
				cout << here->name << endl;
			} else {
				auto res = here->folder.find(c2);
				if (res != here->folder.end()) {
					here = res->second;
					cout << here->name << endl;
				} else {
					cout << here->name << endl;
				}
			}
		}
	}
	
	return 0;
}