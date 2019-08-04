#include <bits/stdc++.h>
using namespace std;
int ans, st;
char str[100'001];
int main() {
	scanf("%s", str);
	for(int i = 0; str[i]; ++i) {
		if(str[i] == '(') st++;
		else {
			st--;
			if(str[i - 1] == '(') ans += st;
			else ans++;
		}
	}
	printf("%d\n", ans);
}

//설명
//사실 그림에 보이는대로 공식 생각해서 풀면 되는 문제이다.
//닫힌 괄호를 만날때마다 스택에 쌓인 열린괄호 갯수 - 1개 만큼 더하면 된다.