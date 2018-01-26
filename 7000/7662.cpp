#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

map<long long, int> m;

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		m.clear();
		int k;
		scanf("%d", &k);

		int front = 0, end = 0;
		while (k--) {
			char command;
			int number;
			scanf(" %c %d", &command, &number);
			if (command == 'I') 
				m[number]++;
			else if (!m.empty()){
				if (number == -1) {
					m.begin()->second--;
					if (m.begin()->second == 0)
						m.erase(m.begin()->first);
				}
				else {
					m.rbegin()->second--;
					if (m.rbegin()->second == 0)
						m.erase(m.rbegin()->first);
				}
			}
		}
		
		if (m.empty())
			printf("EMPTY\n");
		else
			printf("%lld %lld\n", m.rbegin()->first, m.begin()->first);
	}

	return 0;
}