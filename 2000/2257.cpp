#include <iostream>
#include <string>
#define INF 987654321
#define MAXSIZE 5000000
using namespace std;

string str;

int get(int sIdx, int eIdx){
    int result = 0;
    int prev = 0;
    for(int i = sIdx; i <= eIdx; i++){
        if(str[i] == '('){
            int idx = -1;
            int cnt = 1;
            for(int j = i + 1; j <= eIdx; j++){
                if(str[j] == ')')
                    cnt--;
                if(str[j] == '(')
                    cnt++;
                if(cnt == 0){
                    idx = j;
                    break;
                }

            }

            int tmp = get(i + 1, idx - 1);
            prev = tmp;
            result += tmp;
            i = idx;
        }
        else if (isalpha(str[i])){
            if(str[i] == 'H'){
                result += 1;
                prev = 1;
            }
            else if(str[i] == 'C'){
                result += 12;
                prev = 12;
            }
            else if(str[i] == 'O'){
                result += 16;
                prev = 16;
            }
        }
        else if((str[i] >= '2' && str[i] <= '9'))
            result += prev * (str[i] - '0' - 1);

    }

    return result;
}

int main() {
	cin >> str;

    cout << get(0, str.size() - 1) << endl;
	return 0;
}

