#include <bits/stdc++.h>
using namespace std;
struct P{
	int point;
	int index;
};
P p[8];

bool point_sort(const P &a, const P &b){
	return a.point < b.point;
}
bool index_sort(const P &a, const P &b){
	return a.index < b.index;
}
int main(){
	for(int i = 0; i < 8; ++i){
		scanf("%d", &p[i].point);
		p[i].index = i + 1;
	}
	sort(p, p + 8, point_sort);
	int sum = 0;
	for(int i = 3; i < 8; ++i)
		sum += p[i].point;
	p[0].index = p[1].index = p[2].index = -1;
	sort(p, p + 8, index_sort);
	
	printf("%d\n", sum);
	for(int i = 3; i < 8; ++i)
		printf("%d ", p[i].index);
}

// 설명(Sort)
// 정렬하고 더한다음, 없애고 정렬하고 출력