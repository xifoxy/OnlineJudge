#include <bits/stdc++.h>
using namespace std;
int n, fret, ans;
int main() {
	scanf("%d%d", &n, &fret);
	vector<int> vec[7];
	for(int i = 0; i < n; ++i) {
		int line, pos;
		scanf("%d%d", &line, &pos);
		while(vec[line].size() && vec[line].back() > pos)
			vec[line].pop_back(), ans++;
		if(!vec[line].size() || vec[line].back() < pos)
			vec[line].push_back(pos), ans++;
	}
	printf("%d\n", ans);
}

//¼³¸í
//1ÇÁ·§¿¡¼­ ´­·¯¾ß ÇÏ´Â À½ÀÌ 1, 5, 3, 4 ¶ó°í ÇÏ¸é
//Çª½¬ Çª½¬ ÆË Çª½¬ Çª½¬
//5, 1, 5, 1 ÀÌ¸é
//ÇªÆËÇªÆËÇªÆËÇª