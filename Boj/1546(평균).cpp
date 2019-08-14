#include <cstdio>
int d[1001],n, mx;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &d[i]), mx = mx < d[i] ? d[i] : mx;
    
    double s = 0;
    for(int i = 0; i < n; ++i){
        s += double(d[i]) / mx * 100;
    }
    printf("%.2lf\n", s / n);
}

// 쉬어가는 문제