#include <bits/stdc++.h>
int alpha[26], mx;
int main() {
	char ch;
	while(scanf("%c", &ch) != EOF) {
		if(ch >= 'a' && ch <= 'z') {
			alpha[ch - 'a']++;
			mx = std::max(mx, alpha[ch - 'a']);
		}
	}

	for(int i = 0; i < 26; ++i)
		if(alpha[i] == mx)
			printf("%c", i + 'a');
}

// 설명
// 편해 보이는 방법이지만 결코 좋은 소스는 아니다.
// EOF를 기준으로 편하게 받기 위해서 저렇게 이용했지만, 문자열을 기준으로 받을 수 있는
// 그러니까, 행을 기준으로 받을 수 있는 getline이 훨씬 더 효율적일수 있다.
// 위와 같은 방식으로 받으면 scanf가 최대 5천번까지 호출되기 때문이다.