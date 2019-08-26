#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &ans) {
	for(auto &p : ans)
		cout << p << ' ';
}
vector<int> getMatch(const string &A) {
	int n = A.size(), begin = 1, match = 0;
	vector<int> pi(n, 0);
	while(begin + match < n) {
		if(A[begin + match] == A[match])
			pi[begin + match - 1] = ++match;
		else {
			if(!match) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
	return pi;
}
void kmp(const string &A, const string &B) {
	int n = A.size(), m = B.size();
	int cnt = 0, begin = 0, match = 0;
	vector<int> pi = getMatch(B);
	vector<int> ans;
	while(begin <= n - m) {
		if(match < m && A[begin + match] == B[match]) {
			++match;
			if(match == m) {
				cnt++;
				ans.push_back(begin + 1);
			}
		} else {
			if(!match) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
	cout << cnt << '\n';
	print(ans);
}
int main() {
	string A, B;
	getline(cin, A);
	getline(cin, B);
	kmp(A, B);
}

//설명
//KMP탐색 알고리즘의 가장 기본 문제이다.
//간략히 줄이면, getmatch함수는 전톡정인 방법이 아닌 약간 변형된 알고리즘이다.
//함수의 모양을 잘 뜯어보면 kmp의 비교함수와 유사하다는걸 알 수 있다.
//함수 두개를 이해하는것보다 하나로 두개를 이해하는게 좋으니 갓종만 찬양하라.