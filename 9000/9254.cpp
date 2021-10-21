#include <stdio.h>
#include <vector>
#include <cassert>
using namespace std;
/* 행렬 구조체 */
struct Mat {
    vector<vector<double>> data;
    Mat(int n) { data.resize(n, vector<double>(n,0)); }
    double* operator [] (int idx) {
        return &data[idx][0];
    }
    void swapRow(int i, int j) {
        if(i==j) return;
        for(int k=0;k<data.size();k++)
            swap(data[i][k], data[j][k]);
    }
    void setIdentity() {
        for(int i=0;i<data.size();i++)
            for(int j=0;j<data.size();j++)
                if(i==j) data[i][j]=1;
                else data[i][j]=0;
    }
};
/* 역행렬 계산 */
Mat getInverseMatrix(Mat a) {
    int n=a.data.size();
    Mat b(n);
    b.setIdentity();
    for(int k=0;k<n;k++) {
        int t=k-1;
        while(t+1<n && !a[++t][k]);
        if(t==n-1 && !a[t][k]) return Mat(0);
        a.swapRow(k,t), b.swapRow(k,t);
        double d=a[k][k];
        for(int j=0;j<n;j++)
            a[k][j]/=d, b[k][j]/=d;
        for(int i=0;i<n;i++)
            if(i!=k) {
                double m=a[i][k];
                for(int j=0;j<n;j++) {
                    if(j>=k) a[i][j]-=a[k][j]*m;
                    b[i][j]-=b[k][j]*m;
                }
            }
    }
    return b;
}
int main() {
    int n;
    scanf("%d",&n);
    Mat a(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            scanf("%lf", &a[i][j]);
    }
    Mat inv = getInverseMatrix(a);
    if(inv.data.size()>0) {
        for(int i=0;i<n;i++,printf("\n"))
            for(int j=0;j<n;j++)
                printf("%lf ", inv[i][j]);
                //result[i]+=inv[i][j]*b[j];
    } else printf("no inverse");
    return 0;
}
