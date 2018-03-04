#include <bits/stdc++.h>
using namespace std;

deque<int> arr1(4);
deque<int> arr2(4);

bool checkRotate(deque<int>& temp) {
	if (temp[0] != arr2[0])
		return false;
	bool check = true;
	for (int i = 0; i < 3; i++) {
			check = true;
			for (int j = 1; j < 4; j++)
				if (temp[j] != arr2[j]) {
					check = false;
					break;
				}
			if (check)
				break;
			int tmp = temp[1];
			temp.erase(++temp.begin());
			temp.push_back(tmp);
		}
	return check;
}

int main() {
	int k;
	scanf("%d", &k);
	
	while (k--) { 
		for (int i = 0; i < 4; i++)
			scanf("%d", &arr1[i]);
		for (int i = 0; i < 4; i++)
			scanf("%d", &arr2[i]);
			
		bool check = checkRotate(arr1);
		if (!check) {
			deque<int> temp(4);
			temp[0] = arr1[1];
			temp[1] = arr1[3];
			temp[2] = arr1[2];
			temp[3] = arr1[0];
			check = checkRotate(temp);
		}
		if (!check) {
			deque<int> temp(4);
			temp[0] = arr1[2];
			temp[1] = arr1[1];
			temp[2] = arr1[3];
			temp[3] = arr1[0];
			check = checkRotate(temp);
		}
		if (!check) {
			deque<int> temp(4);
			temp[0] = arr1[3];
			temp[1] = arr1[1];
			temp[2] = arr1[0];
			temp[3] = arr1[2];
			check = checkRotate(temp);
		}
        
		printf("%d\n", check);
	}

	return 0;
}