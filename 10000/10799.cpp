#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

queue<char> qu;

int main() {
	char temp;
	while (scanf("%c", &temp) != EOF) 
		qu.push(temp);
	
	int cnt = 0;
	int result = 0;
	while (!qu.empty()) {
		char c = qu.front();
		qu.pop();
		if (c == '(' && qu.front() == ')') {
			result += cnt;
			qu.pop();
		}
		else if (c == '(') {
			cnt++;
		}
		else if (c == ')') {
			cnt--;
			result++;
		}
	}
	printf("%d\n", result);


	return 0;
}