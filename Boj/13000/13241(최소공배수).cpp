#include <bits/stdc++.h>
using namespace std;
long long a, b;
int gcd(long long a, long long b){
	return a % b ? gcd(b, a % b) : b;
}
int main(){
	cin >> a >> b;
	cout << a * b / gcd(a,b);
}

// Ό³Έν(GCD,LCM)