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

        // ���ĺ� ������� üũ�� ���� �ε����� ��ġ�� ����ִ���?
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

// ����(�迭, ����)
// ¥�����Ե� ���� ������ ����� ���� �ʾƼ� 5���̳� Ʋ�ȴ�.
// ���ĺ��� �ߺ� ���ǰų� ���ĺ��� �� �ڸ��� �� ���ԵǸ� !�� ����ؾߵȴ�.