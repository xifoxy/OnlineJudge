#include <bits/stdc++.h>
using namespace std;
vector<int> v, temp;
int n, a;
int sol(vector<int> &vec, int pos = 0) {
	if(vec.size() == 3) {
		int s1 = 1, s2 = 1, s3 = 1, s4 = 1;
		for(int i = 0; i < n; ++i) {
			if(i <= vec[0]) s1 *= v[i];
			else if(i <= vec[1]) s2 *= v[i];
			else if(i <= vec[2]) s3 *= v[i];
			else s4 *= v[i];
		}
		return s1 + s2 + s3 + s4;
	}
	int ret = 0;
	for(int i = pos; i < n - 1; ++i) {
		vec.push_back(i);
		ret = max(ret, sol(vec, i + 1));
		vec.pop_back();
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a);
		v.push_back(a);
	}
	int ans = sol(temp);
	printf("%d\n", ans);
}

//ó���� �ʹ� ��ư� �����Ϸ��� �ؼ� �ڵ尡 �� ���� ������.
//�ܼ��ϰ� ���� ������ ����� �ִ���.
//���ҵǴ� ������ 4�� �� ���Ϸ��� �������� 3���� ���ϸ�
//���ºκ��� 4��° ������ �ȴ�.