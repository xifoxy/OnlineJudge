#include <bits/stdc++.h>
using namespace std;
struct P {
	int st, ed;
};
int n, s, e, ans;
int main() {
	scanf("%d", &n);
	vector<P> v(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &s, &e);
		v[i] = {s,e};
	}
	sort(v.begin(), v.end(), [](const P &u, const P &v) {
		return u.ed < v.ed || (u.ed == v.ed && u.st < v.st);
	});
	/*sort(v.begin(), v.end(), [](const P &u, const P &v) {
		if(u.ed == v.ed)
			return u.st < v.st;
		return u.ed < v.ed;
	});*/
	int start = -1;
	for(int i = 0; i < v.size(); ++i) {
		if(v[i].st >= start) {
			start = v[i].ed;
			ans++;
		}
	}
	printf("%d\n", ans);
}

//����
//���ſ� ��Ʈ ���۷����͸� �� �������� ®���� �� �����ε� ���ذ� ���� �ʴ´�..
//������ �����ϰ� ���̸� ���� ������ ������ �����ؼ� ���ϸ� �ȴ�.
//�����Ͱ� ������ ǥ�� �׷����°� ���� �������̴�.
//������ �ð��� ������ ���۽ð��� ���������� ���� ���ִ� ������
//������ ������
//2 2
//1 2�̷������� �Ǿ� �ִٸ� �ѹ��ۿ� �̿����� ���Ѵ�.
