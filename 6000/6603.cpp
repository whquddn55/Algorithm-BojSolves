#include <cstdio>
#include <vector>

#define INF 987654321
#define MAXSIZE 10000
using namespace std;

vector<int> arr;
int n;

void printPicked(vector<int>& picked) {
    for(int i = 0; i < 6; i++){
        printf("%d ", picked[i]);
    }
    printf("\n");
}

void get(vector<int>& picked,const int idx, const int remain){
    if(remain == 0){
        printPicked(picked);
        return;
    }
    if(idx == n){
        return;
    }

    picked.push_back(arr[idx]);
    get(picked, idx + 1, remain - 1);
    picked.pop_back();
    get(picked, idx + 1, remain);
}

int main() {
    while(true){
        scanf("%d", &n);

        if(n == 0){
            return 0;
        }
        
        arr.clear();
        arr.resize(n);

        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        vector<int> picked;
        get(picked, 0, 6);
        printf("\n");
    }
	return 0;
}

