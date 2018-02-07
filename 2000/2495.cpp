#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

vector<int> arr;

int main() {
	int t = 3;
	while (t--) {
		arr.clear();
		arr.resize(8);
		for (int i = 0; i < 8; i++) {
			char temp;
			scanf(" %c", &temp);
			arr[i] = temp - '0';
		}

		int result = 1;
		int seq = 1;
		int previous = arr[0];
		for (int i = 1; i < 8; i++) {
			if (arr[i] == previous) 
				seq++;
			else {
				seq = 1;
				previous = arr[i];
			}
			result = max(result, seq);
		}
		result = max(result, seq);

		printf("%d\n", result);
	}

	
	return 0;
}