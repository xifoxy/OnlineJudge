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

// 설명
// 주어진 두 문자열의 일치하는 하는 부분을 빼고 전부다 없애주면 애너그램이란다.
// 메모이제이션을 이용해 간단하게 해결가능하다.