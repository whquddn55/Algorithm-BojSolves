#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAXSIZE 1000
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    bool flag = false;
    for(int i = n - 2; i >= 0; i--){
        int min = INF;
        int idx;
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                continue;
            }

            if( min > arr[j]){
                min = arr[j];
                idx = j;
            }
            flag = true;
        }
        if(!flag){
            continue;
        }
        int tmp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = tmp;

        sort(arr.begin() + i + 1, arr.end());
        break;
    }

    if(!flag) {
        printf("-1\n");
    }

    else {
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    

	return 0;
}

