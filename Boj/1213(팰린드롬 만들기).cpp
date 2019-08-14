#include <bits/stdc++.h>
using namespace std;
int d[26], odd_cnt, odd_idx = 99;
string pa, ans;
int main() {
	cin >> pa;
	for(int i = 0; i < pa.size(); ++i)
		d[pa[i] - 'A']++;

	for(int i = 0; i < 26; ++i) if(d[i] % 2) {
		odd_idx = i;
		odd_cnt++;
	}

	if((pa.size() % 2 == 0 && odd_cnt) || odd_cnt > 1) cout << "I'm Sorry Hansoo";
	else {
		for(int i = 0; i < 26; ++i) {
			for(int j = 0; j < d[i] / 2; ++j) {
				ans.push_back(i + 'A');
			}
		}
		cout << ans;
		if(odd_idx != 99) cout << char('A' + odd_idx);
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
}

// 설명(팰린드롬이란? 도라도)
// 주어진 문자열로 팰린드롬을 만들려면 몇가지 조건이 필요하다.
// 1. 문자열의 길이가 짝수일때
//  -문자열의 길이가 짝수인데 짝이 맞지 않는 즉 외자 알파벳이 존재 한다면 팰린드롬을 만들 수 없다.
//   ex) AA(B)(C) 여기서 B와 C가 외자 알파벳이다

// 2. 문자열의 길이가 홀수일때
//  -문자열의 길이가 홀수인데 외자 알파벳이 두개 이상 존재 한다면 팰린드롬을 만들 수 없다.

// 두개의 조건에 해당하지 않는 다면 패린드롬을 만들면 된다.
// 입력된 문자열의 알파벳을 카운트해서 A~Z순서대로 스택에 쌓아 팰린드롬의 전반부를 만들고
// 뒤집어서 후반부를 출력한다.