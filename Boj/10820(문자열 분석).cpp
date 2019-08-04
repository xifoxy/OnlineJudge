#include <bits/stdc++.h>
using namespace std;
char s[105];
int main() {
	while(fgets(s, 105, stdin) != NULL) {
		int s_A = 0, b_A = 0, n = 0, nll = 0;
		for(int i = 0; s[i]; ++i) {
			if(s[i] >= '0' && s[i] <= '9') n++;
			else if(s[i] >= 'a' && s[i] <= 'z') s_A++;
			else if(s[i] >= 'A' && s[i] <= 'Z') b_A++;
			else if(s[i] == ' ') nll++;
		}
		printf("%d %d %d %d\n", s_A, b_A, n, nll);
	}
}

//»ý·«