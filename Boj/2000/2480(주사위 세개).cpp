#include <bits/stdc++.h>
using namespace std;
int d[3];
int main(){
    scanf("%d%d%d", &d[0], &d[1], &d[2]);
    sort(d, d + 3);
    if(d[0] == d[1] && d[1] == d[2])
        printf("%d\n", d[0] * 1000 + 10000);
    else if(d[0] == d[1] || d[1] == d[2])
        printf("%d\n", (d[0] == d[1] ? d[0] : d[1]) * 100 + 1000);
    else printf("%d\n", d[2] * 100);
}

// 생략