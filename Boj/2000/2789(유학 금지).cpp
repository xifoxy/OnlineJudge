#include <bits/stdc++.h>
using namespace std;
bool dp[26];
char str[101], ban_word[10] = {"CAMBRIDGE"};
int main(){
	scanf("%s", str);
	for(int i = 0; ban_word[i]; ++i)
		dp[ban_word[i] - 'A'] = true;

	for(int i = 0; str[i]; ++i){
		if(!dp[str[i] - 'A'])
			printf("%c", str[i]);
	}
}

// 쉬어가는 문제