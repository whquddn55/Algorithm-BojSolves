#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 987654321
using namespace std;

int arr[26];

int main() {
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        arr[tolower(str[i]) - 'a']++;
    }

    int m = 0;
    int result = 0;
    for(int i = 0; i < 26; i++){
        if( m < arr[i]){
            m = arr[i];
            result = i;
        }
    }

    for(int i = 0; i < 26; i++){
        if (m == arr[i] && i != result){
            printf("?\n");
            return 0;
        }
    }
    printf("%c\n", result + 'A');

    return 0;
}
