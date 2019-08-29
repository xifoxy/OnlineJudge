#include <bits/stdc++.h>
using namespace std;
struct node {
	int num, index;
};
int n, a;
int main() {
	scanf("%d", &n);
	deque<node> deq;

	for(int i = 0; i < n; ++i) {
		scanf("%d", &a);
		deq.push_back({a, i + 1});
	}

	int cur = 0;
	for(int i = 0; i < n; ++i) {
		int next = deq[cur].num;
		printf("%d ", deq[cur].index);
		deq.erase(deq.begin() + cur);

        // ��ũ�� ��ü ����� ���߱� ������ ����ϰ�� 1���ش�.
		if(next > 0) next--;
		cur += next;

        // ��ũ ��ü ������(sz ��� deq.size()�� �־��ָ� ������ ���� �� �ִ�)
        // size�Լ��� unsigned int���̱� ������ -���� ������ ������ ���꿡�� �̻��Ѱ��� ���´�.
        // ex) -1 % 4? 4294967295 % 4 �� �ȴ�
		int sz = deq.size();
		if(sz) {
			cur = cur >= 0 ? cur : sz + cur % sz;
			cur %= sz;
		}
	}
}

// ����
// �ε��� ���̸� �ϸ� �ȴ�.
// �̵��ؾ� �ϴ� ������ ���ϱ� �����̸�, ��ũ�� ��ü ũ�⿡�� ������ ������ �ϸ�
// �ε��� ������ ����������, minus��ŭ �̵��ϰ� �Ǹ�
// ��ũ�� ������� ������ ���� ���ذ� ������ �ʿ䰡 �ִ�.