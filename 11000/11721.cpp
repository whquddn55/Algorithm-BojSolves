#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	while (str.size() != 0) {
		if (str.size() < 10) {
			for (int i = 0; i < str.size(); i++)
				cout << str[i];
			cout << endl;
			str = str.substr(str.size());
		}
		else {
			for (int i = 0; i < 10; i++)
				cout << str[i];
			cout << endl;
			str = str.substr(10);
		}
	}

	return 0;
}