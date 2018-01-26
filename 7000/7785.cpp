#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

map<string, bool, greater<string> > m;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char name[201], command[6];
		scanf(" %s %s", name, command);
		if (!strcmp(command, "enter")) 
			m[name] = true;
		else
			m[name] = false;
	}

	for (auto element : m)
		if (element.second == true)
			printf("%s\n", element.first.c_str());

	return 0;
}