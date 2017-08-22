#include <iostream>
#include <string>
#include <algorithm>
#define INF 987654321
#define MAXSIZE 51
using namespace std;


int main() {
	string s1, s2;
	cin >> s1 >> s2;

	if(s1[0] == '0'){
        int cnt = 1;
        for(int i = 1; i < s1.size(); i++){
            if(s1[i] == '1')
                break;
            cnt++;
        }

        for(int i = 0; i + cnt < s1.size(); i++)
            s1[i] = s1[i + cnt];
        s1.resize(s1.size() - cnt);
    }
    if(s2[0] == '0'){
        int cnt = 1;
        for(int i = 1; i < s2.size(); i++){
            if(s2[i] == '1')
                break;
            cnt++;
        }

        for(int i = 0; i + cnt < s2.size(); i++)
            s2[i] = s2[i + cnt];
        s2.resize(s2.size() - cnt);
    }

	bool check = s1.size() > s2.size();
	string result;
	if(check){
        int size = s1.size();
        int dif = size - s2.size();
        for(int i = 0; i < size; i++){
            if(i < dif)
                result.push_back(s1[i] - '0');
            else
                result.push_back(s1[i] + s2[i - dif] - '0' - '0');
        }
	}
	else{
        int size = s2.size();
        int dif = size - s1.size();
        for(int i = 0; i < size; i++){
            if(i < dif)
                result.push_back(s2[i] - '0');
            else
                result.push_back(s1[i - dif] + s2[i] - '0' - '0');
        }
	}


	int size = result.size();
	for(int i = size - 1; i >= 1; i--){
        if(result[i] > 1){
            result[i - 1] += result[i] / 2;
            result[i] %= 2;
        }
	}

    reverse(result.begin(), result.end());
	while(result[result.size() - 1] > 1){
        result.push_back(result[result.size() - 1] / 2);
        result[result.size() - 2] %= 2;
	}
	reverse(result.begin(), result.end());

	for(int i = 0; i < result.size(); i++)
        cout << (int)result[i];

    if(!result.size())
        cout << 0;
    cout << endl;

	return 0;
}

