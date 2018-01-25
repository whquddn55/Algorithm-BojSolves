#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int k, n;
vector<int> arr;
vector<vector<char> > ladder;

vector<int> mid;
vector<int> midPos;
vector<int> last;

int main() {
	scanf("%d %d", &k, &n);
	arr.resize(k);
	for (int i = 0; i < k; i++) {
		char temp;
		scanf(" %c", &temp);
		arr[i] = temp - 'A';
	}

	ladder.resize(n);
	int veiled;
	for (int i = 0; i < n; i++) {
		ladder[i].resize(k);
		for (int j = 0; j < k - 1; j++)
			scanf(" %c", &ladder[i][j]);
		ladder[i][k - 1] = '*';
		if (ladder[i][0] == '?')
			veiled = i;
	}

	mid.resize(k);
	midPos.resize(k);
	for (int i = 0; i < k; i++) {
		int pos = i;
		for (int j = 0; j < veiled; j++) {
			if (ladder[j][pos] == '-')
				pos++;
			else if ((pos - 1 >= 0) && ladder[j][pos - 1] == '-')
				pos--;
		}
		midPos[i] = pos;
		mid[pos] = i;
	}

	last.resize(k);
	for (int i = 0; i < k; i++) {
		int pos = i;
		for (int j = veiled + 1; j < n; j++) {
			if (ladder[j][pos] == '-')
				pos++;
			else if ((pos - 1 >= 0) && ladder[j][pos - 1] == '-')
				pos--;
		}
		last[pos] = mid[i];
	}
	
	vector<int> result(k - 1, false);
	for (int i = 0; i < k; i++) {
		if (arr[i] == last[i])
			continue;
		int pos = min(midPos[arr[i]], midPos[last[i]]);
		if (abs(midPos[arr[i]] - midPos[last[i]]) != 1) {
			for (int i = 0; i < k - 1; i++)
				printf("x");
			printf("\n");
			return 0;
		}
		result[pos] = true;
	}
	for (int i = 0; i < k - 1; i++)
		printf("%c", result[i] ? '-' : '*');
	printf("\n");

	return 0;
}