#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef pair<int, int> pii;

int n, m, k;
map<int, int> arr;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	while (n--) {
		int key, value;
		scanf("%d %d", &key, &value);
		arr[key] = value;
	}

	while (m--) {
		int command, key, value;
		scanf("%d", &command);

		if (command == 1) {
			scanf("%d %d", &key, &value);
			arr[key] = value;
		}
		else if (command == 2) {
			scanf("%d %d", &key, &value);
			map<int, int>::iterator it= arr.upper_bound(key);
			int foundKey1 = it->first;
			int foundKey2 = (--it)->first;
			if (abs(foundKey1 - key) == abs(foundKey2 - key))
				continue;
			int foundKey = (abs(foundKey1 - key) > abs(foundKey2 - key)) ? foundKey2: foundKey1;
			if (abs(foundKey - key) <= k) 
				arr[foundKey] = value;
			
		}
		else {
			scanf("%d", &key);
			map<int, int>::iterator it = arr.upper_bound(key);
			int foundKey1 = it->first;
			int foundKey2 = (--it)->first;
			if (abs(foundKey1 - key) == abs(foundKey2 - key)) {
				printf("?\n");
				continue;
			}
			int foundKey = (abs(foundKey1 - key) > abs(foundKey2 - key)) ? foundKey2 : foundKey1;
			if (abs(foundKey - key) <= k)
				printf("%d\n", arr[foundKey]);
			else
				printf("-1\n");
		}
	}

	return 0;
}