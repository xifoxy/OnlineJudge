#include <bits/stdc++.h>
using namespace std;
int a,b;
void sol(int n){
    if(n == 0) return;
    int mod = n % b;
    sol(n / b);
    if(mod < 10) printf("%d", mod);
    else printf("%c", 'A' + mod - 10);
}
int main(){
    scanf("%d%d",&a,&b);
    sol(a);
}

// ����
// �������̴�. 2745�� ���� ��ȯ�� �ڸ����� �� �ڸ����� ���� �����༭ Ǯ������.
// ���� ��ȯ2 �� 10�������� �־��� �ڿ����� ������ K�������� ��ü�ϴ� �۾��� �ؾ� �ϱ� ������,
// ������ ������ �̿��ؼ� �ڸ��� ���� ���� ���� ����ߴ�.