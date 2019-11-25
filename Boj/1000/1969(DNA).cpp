#include <bits/stdc++.h>
using namespace std;

char b[1000][51];
int n, m;
int main(){
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; ++i)
        scanf("%s", &b[i]);

    int ans = 0;
    for(int y = 0; y < m; ++y){
        int d[26]{}, a = 0;
        for(int x = 0; x < n; ++x){
            char ch = b[x][y] - 'A';
            d[ch]++;
            a = max(a, d[ch]);
        }

        for(int idx = 0; idx < 26; ++idx){
            if(d[idx] == a){
                printf("%c", idx + 'A');
                break;
            }
        }
        ans += (n - a);
    }
    printf("\n%d\n", ans);
}

// 설명
// 문제 설명이 굉장히 거창해 보이나,
// 세로축의 값들을 비교하는 문제이다.