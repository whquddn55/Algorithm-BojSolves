#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int k,b;
    scanf("%d",&b);

    int cas[b];
    for(k=0;k<b;k++){
        int stack=0,total=0,i,j;
        char a [81];
        scanf("%s",a);

        int len = strlen(a);
        for(i=0;i<len;i++){
            if(a[i] == 'O'){
                stack++;
            }
            if(a[i] == 'X'){
                for(j=stack;j>0;j--){
                    total=total+j;
                }
                stack=0;
            }
        }
        for(j=stack;j>0;j--){
            total=total+j;
        }

        cas[k]=total;
        total=0;
    }
    for(k=0;k<b;k++){
        printf("%d\n",cas[k]);
    } 
}