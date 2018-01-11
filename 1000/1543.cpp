#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 2501

int main() {
	char s1[MAXSIZE];
	char s2[51];
	cin.getline(s1, MAXSIZE);
	cin.getline(s2, 51);

	string dox(s1);
	string toFindString(s2);
	int toFindStringSize = toFindString.size();
	int result = 0;
	for (int i = 0; i < dox.size(); i++) {
		int index = dox.find(toFindString, i);
		if (index == -1)
			break;

		i = index + toFindStringSize - 1;
		result++;
	}

	cout << result << endl;

	return 0;
}