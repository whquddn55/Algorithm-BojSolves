#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
char s[10];
char alpha[8][10] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };

int compare(char* a, char* b) {
	int ret = 0;
	for (int i = 0; i < 6; i++)
		ret += (a[i] != b[i]);
	return ret;
}

int main() {
	scanf("%d", &n);
	
	int toPrint = 0;
	vector<char> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			char temp;
			scanf(" %c", &temp);
			s[j] = temp;
		}
		for (int j = 0; j < 8; j++) {
			if (!strcmp(s, alpha[j])) {
				result.push_back('A' + j);
				toPrint = 0;
				break;
			}
			if (compare(s, alpha[j]) == 1) {
				result.push_back('A' + j);
				toPrint = 0;
				break;
			}
			else {
				toPrint = i + 1;
			}
		}
		if (toPrint != 0)
			break;
	}
	if (toPrint != 0) {
		printf("%d\n", toPrint);
	}
	else {
		for (int i = 0; i < n; i++)
			printf("%c", result[i]);
		printf("\n");
	}
	
	return 0;
}