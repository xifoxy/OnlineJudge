#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a, b, c, l = 0, r = 1e10;
	cin >> a >> b >> c;
	while(l < r){
		long long mid = (l + r) / 2;
        // �����̴� �ö󰡰��� ���߶� �̲�������.
		if(mid * a - (mid - 1) * b >= c){
			r = mid;
		} else l = mid + 1;
	}
	cout << l << '\n';
}

// ����(Binary Search)
// �̺�Ž���� �̿��ϸ� ���� Ǯ���� �����̴�.
// ���ǹ��� �� ���캸��.