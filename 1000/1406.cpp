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
using std::swap;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

std::list<char> str;
int n;

int main() {
	while (true) {
		char t;
		scanf("%c", &t);
		if (t == '\n')
			break;
		str.push_back(t);
	}
	scanf("%d", &n);

	auto it = str.end();
	while (n--) {
		char command;
		scanf(" %c", &command);
		switch (command) {
		case 'L':
			if (it != str.begin())
				it--;
			break;
		case 'D':
			if (it != str.end())
				it++;
			break;
		case 'P': 
			char character;
			scanf(" %c", &character);
			str.insert(it, character);
			break;
		
		case 'B':
			if (it != str.begin()) {
				auto itTemp = it;
				itTemp--;
				str.erase(itTemp);
			}
			break;
		}
	}

	for (auto& e : str)
		printf("%c", e);


	return 0;
}