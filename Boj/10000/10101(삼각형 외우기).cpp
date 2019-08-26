#include <bits/stdc++.h>
using namespace std;
int d[3];
int main() {
	cin >> d[0] >> d[1] >> d[2];
	sort(d, d + 3);
	int sum = d[0] + d[1] + d[2];
	if(sum != 180) puts("Error");
	else {
		if(d[0] == d[1])
			printf("%s\n", d[1] == d[2] ? "Equilateral" : "Isosceles");
		else if(d[1] == d[2])
			puts("Isosceles");
		else puts("Scalene");
	}
}

// 왜 60프로가 안되는지 이해가 안된다.