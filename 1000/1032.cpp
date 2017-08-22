#include <iostream>
#include <string>
#define INF 987654321
#define MAXSIZE 51
using namespace std;


int main() {
	int n;
	cin >> n;

	string arr[MAXSIZE];
	for(int i = 0; i < n; i++)
        cin >> arr[i];

    int strsize = arr[0].size();
    string result;
    for(int i = 0; i < strsize; i++){
        bool isEqual = true;
        char front = arr[0][i];
        for(int j = 1; j < n; j++){
            if(arr[j][i] != front){
                isEqual = false;
                break;
            }
        }
        if(isEqual)
            result.push_back(front);
        else
            result.push_back('?');
    }

    cout << result << endl;

	return 0;
}

