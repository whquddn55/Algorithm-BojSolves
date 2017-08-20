#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAXSIZE 1001

int idx[26];

int main() {
	string str;
	cin >> str;

	int idx[26];
	memset(idx, -1, sizeof(idx));

	int size = str.size();
	for(int i = 0; i < size; i++)
		if(idx[str[i] - 'a'] == -1)
			idx[str[i] - 'a'] = i;

	for(int i = 0; i < 26; i++)
		cout << idx[i] << ' ';


	return 0;
}
