#include <bits/stdc++.h>
using namespace std;
const int M = 1e3;
struct P{
	int num;
	int f_idx;
	int s_idx;
};
P arr[M];
bool cmp(const P &a, const P &b){
	return a.num == b.num ? a.f_idx < b.f_idx : a.num < b.num;
}
bool cmp2(const P &a, const P &b){
	return a.f_idx < b.f_idx;
}
int main(){
	int n; 
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i].num);
		arr[i].f_idx = i;
	}

	sort(arr, arr + n, cmp);
	for(int i = 0; i < n; ++i){
		arr[i].s_idx = i;
	}
	sort(arr, arr + n, cmp2);
	for(int i = 0; i < n; ++i){
		printf("%d ", arr[i].s_idx);
	}
}

// 설명(Sort)
// 문제 설명이 좀 거지같다..
// 그러니까...
// 입력받고 첫번째 인덱스부여 -> 입력 오름차순 정렬 + 두번째 인덱스 부여 ->
// 첫번째 인덱스로 오름차순 정렬 -> 두번째 인덱스 출력이다.
// 주의해야할건 입력으로 들어오는 숫자가 같을 경우 첫번째로 부여할 인덱스 순서로 정렬해야한다.