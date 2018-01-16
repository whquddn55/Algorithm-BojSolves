#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n;
vector<vector<int> > adj;
vector<int> path;

void floyd() {
	for (int k = 0; k < 52; k++)
		for (int i = 0; i < 52; i++)
			for (int j = 0; j < 52; j++) 
					adj[i][j] =  min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
	scanf("%d", &n);

	adj.resize(52);
	for (int i = 0; i < 52; i++) 
		adj[i].resize(52, INF);
	
	for (int i = 0; i < n; i++) {
		char from, to;
		scanf(" %c => %c", &from, &to);
		
		if (from >= 'A' && from <= 'Z')
			from -= 'A';
		else if (from >= 'a' && from <= 'z')
			from = from - 'a' + 26;
		if (to >= 'A' && to <= 'Z')
			to -= 'A';
		else if (to >= 'a' && to <= 'z')
			to = to - 'a' + 26;
		adj[from][to] = 1;
	}

	floyd();

	int cnt = 0;
	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
			if (adj[i][j] != INF && i != j)
				cnt++;
	printf("%d\n", cnt);
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (adj[i][j] != INF && i != j)
				printf("%c => %c\n", (i < 26) ? (i + 'A') : (i - 26+ 'a'), (j < 26) ? (j + 'A') : (j - 26 + 'a'));
		}
	}

	return 0;
}