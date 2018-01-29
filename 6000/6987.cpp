#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

int n, k;
int arr[6][3];
int genWin[6];
int genLose[6];
int genDraw[6];
int p1[15], p2[15];
bool result;

void get(int cnt) {
	if (cnt == 15) {
		result = true;
		return;
	}

	int n1 = p1[cnt];
	int n2 = p2[cnt];

	genWin[n1]++; genLose[n2]++;
	if (genWin[n1] <= arr[n1][0] && genLose[n2] <= arr[n2][2])
		get(cnt + 1);
	genWin[n1]--; genLose[n2]--;
	
	genDraw[n1]++; genDraw[n2]++;
	if (genDraw[n1] <= arr[n1][1] && genDraw[n2] <= arr[n2][1])
		get(cnt + 1);
	genDraw[n1]--; genDraw[n2]--;
	
	genLose[n1]++; genWin[n2]++;
	if (genLose[n1] <= arr[n1][2] && genWin[n2] <= arr[n2][0])
		get(cnt + 1);
	genLose[n1]--; genWin[n2]--;
}

int main() {
	for (int t= 0; t < 4; t++) {
		for (int i = 0; i < 18; i++)
			scanf("%d", &arr[i / 3][i % 3]);

		result = false;
		bool flag = false;
		for (int i = 0; i < 6; i++) {
			genWin[i] = 0;
			genLose[i] = 0;
			genDraw[i] = 0;
			if (arr[i][0] + arr[i][1] + arr[i][2] != 5) {
				printf("%d ", result);
				flag = true;
				break;
			}
		}
		if (flag)
			continue;

		int cnt = 0;
		for (int i = 0; i < 6; i++)
			for (int j = i + 1; j < 6; j++) {
				p1[cnt] = i;
				p2[cnt] = j;
				cnt++;
			}
		get(0);

		printf("%d ", result);
	}
		


	return 0;
}