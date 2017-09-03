#include <cstdio>
#include <vector>
#include <cstring>

#define INF 987654321
#define MAXSIZE 21
using namespace std;

int arr;

int main() {
    int n;
    scanf("%d", &n);

    while(n--){
        char com[10];
        scanf("%s", com);
        if(!strcmp(com, "add")){
            int idx;
            scanf("%d", &idx);

            arr = arr | (1 << (idx - 1));
        }
        else if(!strcmp(com, "remove")){
            int idx;
            scanf("%d", &idx);

            arr = arr & (1048575 ^(1 << (idx - 1)));
        }
        else if(!strcmp(com, "check")){
            int idx;
            scanf("%d", &idx);

            printf("%d\n", (int)((arr & (1 << (idx - 1))) == (1 << (idx - 1))));
        }
        else if(!strcmp(com, "toggle")){
            int idx;
            scanf("%d", &idx);

            arr = arr ^ (1 << (idx - 1));
        }
        else if(!strcmp(com, "all")){
            arr = 1048575;
        }
        else if(!strcmp(com, "empty")){
            arr = 0;
        }
    }

	return 0;
}

