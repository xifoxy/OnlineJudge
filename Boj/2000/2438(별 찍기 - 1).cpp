#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
         for(int j = 0; j <= i; ++j)
             printf("*");
        puts("");
    }
}

// 이런거 못풀면 자살해야된다.