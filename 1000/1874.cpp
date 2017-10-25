#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
int main(void){
    stack <int> sta;
    vector <char> ans;
    
    int s[100001];
    int N, pos=1;
    scanf("%d", &N);
    
    for(int i=1;i<=N;++i) scanf("%d", &s[i]);
    
    for(int i=1;i<=N;++i){
        sta.push(i);
        ans.push_back('+');
        
        while(!sta.empty()&&sta.top()==s[pos]){
            sta.pop();
            ans.push_back('-');
            pos++;
        }
    }
    
    if(!sta.empty()) printf("NO\n");
    else
        for(int i=0;i<ans.size();++i)
            printf("%c\n", ans[i]);
            
    return 0;
}