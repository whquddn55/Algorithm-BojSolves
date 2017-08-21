#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 125
#define INF 987654321

int main() {
	int arr[8];
	for(int i = 0; i < 8; i++)
		cin >> arr[i];

	bool ascend = true, descend = true;
	for(int i = 0; i < 8; i++){
		if(arr[i] == i + 1 && ascend)
			descend = false;
		else if (arr[i] == 8 - i && descend)
			ascend = false;
		else {
			descend = false;
			ascend = false;
			break;
		}
	}

	if(ascend)
		cout << "ascending" << endl;
	else if(descend)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;


	return 0;
}

