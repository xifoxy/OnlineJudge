#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> d_min(2, vector<int>(3, 0)), d_max;
    d_max = d_min;
    int a, b, c, n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d%d%d",&a ,&b ,&c);
        d_min[1][0] = a + min(d_min[0][0], d_min[0][1]);
        d_min[1][1] = b + min(d_min[0][0], min(d_min[0][1], d_min[0][2]));
        d_min[1][2] = c + min(d_min[0][1], d_min[0][2]);

        d_max[1][0] = a + max(d_max[0][0], d_max[0][1]);
        d_max[1][1] = b + max(d_max[0][0], max(d_max[0][1], d_max[0][2]));
        d_max[1][2] = c + max(d_max[0][1], d_max[0][2]);

        d_min[0] = d_min[1];
        d_max[0] = d_max[1];
    }

    printf("%d ", max(d_max[0][0], max(d_max[0][1], d_max[0][2])));
    printf("%d\n", min(d_min[0][0], min(d_min[0][1], d_min[0][2])));
}

// ����(DP)
// �������鼭 ����� �ִ� �ִ񰪰� �ּڰ��� ����� ����ϸ� �ȴ�.
// �����ؾ��� ���� �����´ٴ� ���⼺�� �ֱ� ������
// d_min[0] += min(a,b);
// d_min[1] += min(a, min(b,c));
// d_min[2] += min(b,c);
// �̷������� ¥������ �Ǹ� ���⼺�� �Ҿ������ �Ǵ� ��������.