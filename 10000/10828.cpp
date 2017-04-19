#include <iostream>
#include <string>
using namespace std;
typedef unsigned int uint;

int main() {
	uint stack[10001], stackLen = 0;

	uint num;
	cin >> num;
	for (uint i = 0; i < num; i++) {
		string input;
		cin >> input;
		if (!input.compare("push")) {
			uint value;
			scanf("%d", &value);
			stack[stackLen] = value;
			stackLen++;
		}
		else if (!input.compare("pop")) {
			if (stackLen == 0)
				printf("-1\n");
			else {
				stackLen--;
				printf("%d\n", stack[stackLen]);
			}
		}
		else if (!input.compare("size")) {
			printf("%d\n", stackLen);
		}
		else if (!input.compare("empty")) {
			if (stackLen == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!input.compare("top")) {
			if (stackLen == 0)
				printf("-1\n");
			else 
				printf("%d\n", stack[stackLen - 1]);
			
		}
	}
	return 0;
}