#include <bits/stdc++.h>
using std::pair;
using std::vector;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::deque;
using std::greater;
using std::max;
using std::min;
using std::sort;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::make_pair;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

char str[102];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	char cambridge[10] = "CAMBRIDGE";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++)
			if (str[i] == cambridge[j]) {
				str[i] = 0;
				break;
			}

		if (str[i] != 0)
			printf("%c", str[i]);
	}

}