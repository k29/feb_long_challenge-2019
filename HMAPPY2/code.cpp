#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    long long t;

    while (b != 0) {
        t = b;
        b = a % t;
        a = t;
    }

    return a;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int t;
	scanf("%d", &t);
	while(t--){
	    long long a, b;
	    long long n, k;
	    scanf("%lld %lld %lld %lld", &n, &a, &b, &k);
	    
	    long long appy = n/a;
        long long chef = n/b;
        long long leastcm = lcm(a, b);
	    long long common = n/leastcm;
	    ((appy+chef-(2*common)) >= k) ? printf("Win\n") : printf("Lose\n");
	    
	}
	return 0;
}
