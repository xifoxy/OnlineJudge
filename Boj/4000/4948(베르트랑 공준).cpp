#include <bits/stdc++.h>
using namespace std;
const int MAX = 25e4;
int d[MAX];
int main() {
	for(int i = 2; i * i <= MAX - 1; ++i) {
		if(!d[i]) for(int j = i * i; j <= MAX - 1; j += i) {
			d[j] = true;
		}
	}
	while(1) {
		int a, cnt = 0; cin >> a;
		if(a == 0) return 0;
		for(int i = a + 1; i <= a * 2; ++i) {
			if(!d[i]) cnt++;
		}
		cout << cnt << '\n';
	}
}

//����
//����. �־��� ���ǿ� ������ �ʴ´ٸ�..
//N <= 123456 -> 2N