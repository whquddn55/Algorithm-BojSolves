#include <iostream>
using namespace std;

int main() {
	char str[101];
	while (fgets(str, sizeof(str), stdin) != NULL) {
		cout << str;
	}

	return 0;
}