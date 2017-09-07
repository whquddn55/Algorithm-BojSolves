#include <cstdio>
#include <vector>
#include <cstdint>
#include <queue>

#define INF 987654321
#define MAXSIZE 1000
using namespace std;

vector<int> waitTime;
int n, m;

bool get(long long mid){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += mid / waitTime[i];
    }

    if(sum < m){
        return true;
    }
    else {
        return false;
    }
}

long long binarySearch(long long left, long long right){
    long long result = 0;
    while(left <= right){
        long long mid = (left + right) / 2;

        bool check = get(mid);
        if(check){
            left = mid + 1;
        }
        else{
            result = mid;
            right = mid - 1;
        }

    }
    return result;
}

int main() {
    scanf("%d %d", &n, &m);

    waitTime.resize(n);

    long long max = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &waitTime[i]);
        max = max < waitTime[i] ? waitTime[i] : max;
    }

    printf("%lld\n", binarySearch(1, max * m));
    return 0;
}
