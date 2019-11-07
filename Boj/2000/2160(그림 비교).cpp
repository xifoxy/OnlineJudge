#include <bits/stdc++.h>
using namespace std;

char board[51][5][8];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 5; ++j){
			scanf("%s", &board[i][j]);
		}
	}

	int ans = 999;
	int fir, sec;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){

			int cnt = 0;
			for(int hei = 0; hei < 5; ++hei){
				for(int wid = 0; wid < 7; ++wid){
					if(board[i][hei][wid] != board[j][hei][wid]){
						cnt++;
					}
				}
			}
			if(ans > cnt){
				fir = i;
				sec = j;
				ans = cnt;
			}
		}
	}
	printf("%d %d\n", fir + 1, sec + 1);
}

// 설명
// 주어진 그림을 비교하면 된다.