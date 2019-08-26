#include <bits/stdc++.h>
using namespace std;
int min_score[3], max_score[3];
int a, b, c;
int main(){
    int n;
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    min_score[0] = max_score[0] = a;
    min_score[1] = max_score[1] = b;
    min_score[2] = max_score[2] = c;

    for(int floor = 2; floor <= n; ++floor){
        scanf("%d%d%d", &a, &b, &c);
        min_score[0] += min(a,b);
        min_score[1] += min(a, min(b,c));
        min_score[2] += min(b,c);

        max_score[0] += max(a,b);
        max_score[1] += max(a, max(b,c));
        max_score[2] += max(b,c);
    }

    printf("%d ", max(max_score[0], max(max_score[1], max_score[2])));
    printf("%d\n", min(min_score[0], min(min_score[1], min_score[2])));
}
//