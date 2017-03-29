#include <iostream>
using namespace std;

int main() {
	int arr1[3], arr2[3], result[3];

	scanf("%d:%d:%d", &arr1[0], &arr1[1], &arr1[2]);
	scanf("%d:%d:%d", &arr2[0], &arr2[1], &arr2[2]);

	for (int i = 0; i < 3; i++) {
		result[i] = arr2[i] - arr1[i];
	}

	if (result[2] < 0) {
		result[1] -= 1;
		result[2] += 60;
	}
	if (result[1] < 0) {
		result[0] -= 1;
		result[1] += 60;
	}
	if (result[0] < 0)
		result[0] += 24;
	

	printf("%02d:%02d:%02d\n", result[0], result[1], result[2]);

	return 0;
}