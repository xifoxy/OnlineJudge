#include <bits/stdc++.h>
using namespace std;
bool d[10001];
void sol() {
	for(int i = 1; i <= 10000; ++i) {
		int t = i, sum = i;
		while(t > 0) {
			sum += (t % 10);
			t /= 10;
		}
		d[sum] = true;
	}
}
int main() {
	sol();
	for(int i = 1; i <= 10000; ++i)
		if(!d[i]) cout << i << '\n';
}

//�˰��� ó�����Ҷ� Ǯ���� ������ �������� �ٽ� Ǯ���.
//�Ѷ� �ؽ� ���蹮�� ���ٴ°� ��￡ �ִ� ������.