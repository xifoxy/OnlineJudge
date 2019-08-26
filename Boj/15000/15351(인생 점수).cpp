#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
	int tc;
	cin >> tc;
	cin.ignore();
	while(tc--) {
		getline(cin, str);
		int sum = 0;
		for(int i = 0; i < str.size(); ++i) {
			if(isalpha(str[i])) {
				sum += (str[i] - 'A' + 1);
			}
		}
		if(sum == 100) puts("PERFECT LIFE");
		else printf("%d\n", sum);
	}
}

// 설명
// 문자열 입력때문에 버퍼를 비워줄 필요가 있다.
// C에서는 scanf("%d\n") or fflush(stdin) 이라는 방법이 있고
// C++에서는 cin.ignore() 라는 함수가 존재한다.
// 문자열을 점수로 치환할때 알파벳체크 유무만 주의하면 된다.