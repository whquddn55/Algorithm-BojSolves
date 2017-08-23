#include <iostream>
#include <string>
#define INF 987654321
#define MAXSIZE 5000000
using namespace std;


int main() {
    string str;
	cin >> str;

    int size = str.size();
    int result = 0;
    for(int i = 0; i < size; i++){
        if(i + 1 < size && str[i] == 'c' && (str[i + 1] == '=' || str[i + 1] == '-')){
            i++;
            result++;
            continue;
        }
        if(i + 1 < size && str[i] == 'd' && str[i + 1] == '-'){
            i++;
            result++;
            continue;
        }
        if(i + 1 < size && str[i] == 'l' && str[i + 1] == 'j'){
            i++;
            result++;
            continue;
        }
        if(i + 1 < size && str[i] == 'n' && str[i + 1] == 'j'){
            i++;
            result++;
            continue;
        }
        if(i + 1 < size && str[i] == 's' && str[i + 1] == '='){
            i++;
            result++;
            continue;
        }
        if(i + 1 < size && str[i] == 'z' && str[i + 1] == '='){
            i++;
            result++;

            continue;
        }
        if(i + 2 < size && str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '='){
            i += 2;
            result++;
            continue;
        }
        result++;
    }
    cout << result << endl;
	return 0;
}

