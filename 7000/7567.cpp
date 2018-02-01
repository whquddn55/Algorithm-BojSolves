#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

queue<char> qu;

int main() {
	char temp;
	while (scanf(" %c", &temp) != EOF)
		qu.push(temp);

	char prev = qu.front();
	qu.pop();
	int result = 10;

	while (!qu.empty()) {
		char here = qu.front();
		qu.pop();

		if (prev == here)
			result += 5;
		else
			result += 10;

		prev = here;
	}

	printf("%d\n", result);

	return 0;
}