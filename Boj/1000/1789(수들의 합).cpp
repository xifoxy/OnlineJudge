#include <bits/stdc++.h>
using namespace std;
long long a, sum;
int i;
int main(){
	scanf("%lld", &a);
	for(;;++i){
		sum += i;
		if(sum > a) break;
	}
	printf("%d\n", i - 1);
}

// ����
// ���� ������ ����������, �׳� ������ 1 �� ���������� ����
// �־��� N �۰ų� ���� ���� ������ A[i] �� ���ϴ� �����̴�.