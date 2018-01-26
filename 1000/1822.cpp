#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

vector<long long> arrA;
bool checked[500001];
int nA, nB;

int main() {
	scanf("%d %d", &nA, &nB);
	arrA.resize(nA);
	for (int i = 0; i < nA; i++) 
		scanf("%d", &arrA[i]);
	sort(arrA.begin(), arrA.end());

	int cnt = nA;
	for (int i = 0; i < nB; i++) {
		int element;
		scanf("%d", &element);

		int index = lower_bound(arrA.begin(), arrA.end(), element) - arrA.begin();
		if (index < nA && arrA[index] == element) {
			checked[index] = true;
			cnt--;
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < nA; i++)
		if (!checked[i])
			printf("%d ", arrA[i]);

	return 0;
}