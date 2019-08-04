#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	vector<int> vec;
	for(int i = 0; i < n; ++i) vec.push_back(i + 1);
	
	int pos;
	printf("<%d", vec[pos = k - 1]);
	while(vec.size() > 1) {
		vec.erase(vec.begin() + pos);
		pos = (pos + k - 1) % vec.size();
		printf(", %d", vec[pos]);
	}
	puts(">");
}

//쉽다