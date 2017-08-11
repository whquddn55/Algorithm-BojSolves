#include <iostream>
using namespace std;

int main() {
	char str[1000002];
	fgets(str, sizeof(str)* sizeof(char), stdin);

	int size;
	for(int i = 0; i < 1000002; i++)
		if(str[i] == '\0' || str[i] == '\n'){
			size = i;
			break;
		}

	int cnt = 0;
	if (str[0] != ' ' && str[0] != '\0' && str[0] != '\n')
		cnt++;

	for(int i = 1; i < size; i++){
		if(str[i - 1] == ' ' && str[i] != ' ')
			cnt++;
	}

	cout << cnt << endl;
	return 0;
}
