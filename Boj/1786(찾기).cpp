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

//����
//KMPŽ�� �˰����� ���� �⺻ �����̴�.
//������ ���̸�, getmatch�Լ��� �������� ����� �ƴ� �ణ ������ �˰����̴�.
//�Լ��� ����� �� ���� kmp�� ���Լ��� �����ϴٴ°� �� �� �ִ�.
//�Լ� �ΰ��� �����ϴ°ͺ��� �ϳ��� �ΰ��� �����ϴ°� ������ ������ �����϶�.