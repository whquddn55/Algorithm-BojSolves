#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 125
#define INF 987654321

int main() {
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		string str;
		cin >> str;

		int size = str.size();
		for(int i = 0; i < size; i++)
			for(int j = 0; j < n; j++)
				cout << str[i];
		cout << endl;
	}


	return 0;
}

