#include <bits/stdc++.h>
using namespace std;
int wheel_size, cnt, idx;
bool dp[26];
char wheel[26];
int main() {
	bool ans = true;
	scanf("%d %d", &wheel_size, &cnt);
	fill(&wheel[0], &wheel[wheel_size], '?');
	for(int i = 0; i < cnt; ++i) {
		int change;
		char ch;
		scanf("%d %c", &change, &ch);
		idx = (idx + change) % wheel_size;
		if(wheel[idx] == ch) continue;

        // 알파벳 사용유무 체크와 현재 인덱스의 위치가 비어있는지?
		if(dp[ch - 'A'] || wheel[idx] != '?') ans = false;
		dp[ch - 'A'] = true;
		wheel[idx] = ch;
	}
	if(ans) {
		for(int i = 0; i < wheel_size; ++i) {
			if(idx < 0) idx = wheel_size - 1;
			printf("%c", wheel[idx]);
			idx--;
		}
	} else puts("!");
}

// 설명(배열, 구현)
// 짜증나게도 문제 설명을 제대로 읽지 않아서 5번이나 틀렸다.
// 알파벳이 중복 사용되거나 알파벳이 들어간 자리에 또 들어가게되면 !를 출력해야된다.