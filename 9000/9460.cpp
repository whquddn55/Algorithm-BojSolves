#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAXSIZE 1000
using namespace std;

vector<pair<int,int> > pos;
int n, k;

bool get(int mid){
    int min = INF, max = -INF;
    int tunnel = k - 1;
    for(int i = 0; i < n; i++){
        int y = pos[i].second;

        min = min > y ? y : min;
        max = max < y ? y : max;

        if(max == -INF || min == INF){
            continue;
        }

        int dist = (max - min) / 2;
        if(dist <= mid){
            continue;
        }

        tunnel--;
        min = max = y;
    }

    return tunnel < 0;
}

double binarySearch(int left, int right){
    int result = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        bool check = get(mid);

        //printf("%d, %d, %d\n", left, right, mid);
        if(check){
            left = mid + 1;
        }
        else{
            result = mid;
            right = mid - 1;
        }

    }
    return (double)result / 2;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d %d", &n, &k);

        pos.resize(n);

        int max = -INF;
        for(int i = 0; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            y *= 2;
            pos[i] = make_pair(x, y);
            max = max < y ? y : max;
        }

        sort(pos.begin(), pos.end());

        printf("%.1lf\n", binarySearch(0, max * 2 + 1));
    }
    return 0;
}
