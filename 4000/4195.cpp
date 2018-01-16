#include <bits/stdc++.h>
using namespace std;

struct Nds{
	vector<int> parent, rank;
	Nds(int n)
		: parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u)
			return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v)
			return;

		if (rank[u] > rank[v])
			swap(u, v);

		parent[u] = v;
		if (rank[u] == rank[v])
			rank[v]++;
	}
};

int f;
map<string, int> m;
vector<int> numOfFriends;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		m.clear();
		scanf("%d", &f);

		int cnt = 0;
		Nds set(2 * f);
		numOfFriends.resize(2 * f);
		while (f--) {
			char s1[30], s2[30];
			scanf("%s %s", s1, s2);
			
			if (m.find(s1) == m.end()) {
				m.insert(make_pair(s1, cnt));
				numOfFriends[cnt] = 1;
				cnt++;
			}
			if (m.find(s2) == m.end()) {
				m.insert(make_pair(s2, cnt));
				numOfFriends[cnt] = 1;
				cnt++;
			}

			int idx1 = set.find(m.find(s1)->second);
			int idx2 = set.find(m.find(s2)->second);

			set.merge(idx1, idx2);
			int newIdx = set.find(m.find(s1)->second);
			if (idx1 != idx2)
				numOfFriends[newIdx] = numOfFriends[idx1] + numOfFriends[idx2];

			printf("%d\n", numOfFriends[newIdx]);
		}
	}

	return 0;
}