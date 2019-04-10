#include <iostream>
#include <cstdio>
#include <limits.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        char temp;
        long long min = LLONG_MAX;
        long long a;
        long long sum=0;
        while(n--){
            scanf("%lld%c", &a, &temp);
            sum+=a-1;
        }
        printf("%lld\n", sum+1);
    }

    return 0;
}