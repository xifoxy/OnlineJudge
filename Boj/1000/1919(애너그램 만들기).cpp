#include <bits/stdc++.h>
using namespace std;
string anagram;
int dp[26];
int main() {
	cin >> anagram;
	for(int i = 0; i < anagram.size(); ++i)
		dp[anagram[i] - 'a']++;
	
	cin >> anagram;
	for(int i = 0; i < anagram.size(); ++i)
		dp[anagram[i] - 'a']--;

	int ans = 0;
	for(int i = 0; i < 26; ++i) {
		ans += abs(dp[i]);
	}
	printf("%d\n", ans);
}

// ����
// �־��� �� ���ڿ��� ��ġ�ϴ� �ϴ� �κ��� ���� ���δ� �����ָ� �ֳʱ׷��̶���.
// �޸������̼��� �̿��� �����ϰ� �ذᰡ���ϴ�.